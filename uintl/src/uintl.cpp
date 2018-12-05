#include <sqlite3.h>
#include <stone/utils.h>
#include <uintl.h>

#include <clocale>
#include <mutex>
#include <unordered_map>
#include <vector>

constexpr auto create_table =
    R"create_table(
      create table if not exists uintl(
        domain text not null,
        key text not null,
        lang text not null,
        value text not null,
        primary key (domain, key, lang)
      );
    )create_table";

namespace uintl {

static thread_local char const *domain = "stone";

struct UIntl {
  sqlite3 *db;
  sqlite3_stmt *select_stmt;
  sqlite3_stmt *insert_stmt;

  UIntl();
  ~UIntl();
  char const *operator[](char const *);
};

UIntl::UIntl() {
  using namespace std::string_literals;
  if (sqlite3_open((PathHelper::getPrimaryDataDirectory() + "uintl.db").c_str(), &db) != SQLITE_OK) {
    throw std::runtime_error("Cannot open uintl database "s + PathHelper::getPrimaryDataDirectory() + "uintl.db: "s + sqlite3_errmsg(db));
  }
  char *err;
  if (sqlite3_exec(db, create_table, nullptr, nullptr, &err) != SQLITE_OK) { throw std::runtime_error("Cannot create table: "s + err); }
  sqlite3_exec(db, "PRAGMA journal_mode=WAL", nullptr, nullptr, nullptr);
  sqlite3_exec(db, "PRAGMA synchronous=NORMAL", nullptr, nullptr, nullptr);
  const auto LANG = GetEnvironmentVariableOrDefault(
      "STONE_LANG", GetEnvironmentVariableOrDefault("LC_MESSAGES", GetEnvironmentVariableOrDefault("LC_ALL", "en_US.UTF-8")));
  std::string select = ("select value from uintl where lang='"s + LANG + "' and domain=? and key=?;"s).c_str();
  std::string insert = ("insert into uintl values (?, ?, '"s + LANG + "', ?);"s).c_str();
  if (sqlite3_prepare_v2(db, select.c_str(), -1, &select_stmt, nullptr) != SQLITE_OK) {
    throw std::runtime_error("Cannot create select stmt: "s + sqlite3_errmsg(db));
  }
  if (sqlite3_prepare_v2(db, insert.c_str(), -1, &insert_stmt, nullptr) != SQLITE_OK) {
    throw std::runtime_error("Cannot create insert stmt: "s + sqlite3_errmsg(db));
  }
}

UIntl::~UIntl() { sqlite3_close(db); }

char const *UIntl::operator[](char const *inp) {
  using namespace std::string_literals;
  static std::mutex mtx;
  std::lock_guard<std::mutex> lock(mtx);
  sqlite3_reset(select_stmt);
  sqlite3_bind_text(select_stmt, 1, domain, -1, SQLITE_STATIC);
  sqlite3_bind_text(select_stmt, 2, inp, -1, SQLITE_STATIC);
  auto rc = sqlite3_step(select_stmt);
  if (rc == SQLITE_ROW) {
    return (char const *)sqlite3_column_text(select_stmt, 0);
  } else if (rc == SQLITE_DONE) {
    sqlite3_reset(insert_stmt);
    sqlite3_bind_text(insert_stmt, 1, domain, -1, SQLITE_STATIC);
    sqlite3_bind_text(insert_stmt, 2, inp, -1, SQLITE_STATIC);
    sqlite3_bind_text(insert_stmt, 3, inp, -1, SQLITE_STATIC);
    if (sqlite3_step(insert_stmt) != SQLITE_DONE) { throw std::runtime_error("Cannot insert into uintl db: "s + sqlite3_errmsg(db)); }
    return inp;
  }
  throw std::runtime_error("Cannot query from uintl db: "s + sqlite3_errmsg(db));
}

char const *gettext(char const *inp) {
  static UIntl intl;
  return intl[inp];
}
void intl_domain(char const *new_domain) { domain = new_domain; }
} // namespace uintl