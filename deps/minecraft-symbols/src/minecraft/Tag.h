#pragma once

struct IDataInput;
struct IDataOutput;
struct PrintStream;

#include "std/string.h"

#include <map>
#include <memory>
#include <vector>

struct Tag {
  virtual ~Tag();
  virtual void deleteChildren();
  virtual void write(IDataOutput &) const = 0;
  virtual void load(IDataInput &)         = 0;
  virtual mcpe::string toString() const   = 0;
  virtual int getId() const               = 0;
  virtual bool equals(Tag const &) const;
  virtual void print(PrintStream &) const;
  virtual void print(mcpe::string const &, PrintStream &) const;
  virtual void setName(mcpe::string const &);
  virtual mcpe::string getName() const;
  virtual std::unique_ptr<Tag> copy() const = 0;
};

struct EndTag : Tag {
  /// @symbol _ZTV6EndTag
  static void **vt;

  virtual void write(IDataOutput &) const;
  virtual void load(IDataInput &);
  virtual mcpe::string toString() const;
  virtual int getId() const;
  virtual bool equals(Tag const &) const;
  virtual std::unique_ptr<Tag> copy() const;
};

struct DoubleTag : Tag {
  /// @symbol _ZTV9DoubleTag
  static void **vt;

  double value;
  virtual void write(IDataOutput &) const;
  virtual void load(IDataInput &);
  virtual mcpe::string toString() const;
  virtual int getId() const;
  virtual bool equals(Tag const &) const;
  virtual std::unique_ptr<Tag> copy() const;
};

struct TagMemoryChunk {
  size_t m_cap, m_size;
  std::unique_ptr<std::byte[]> m_data;

  TagMemoryChunk(TagMemoryChunk &&rhs) {
    m_cap  = rhs.m_cap;
    m_size = rhs.m_size;
    m_data = std::move(rhs.m_data);
  }
  TagMemoryChunk() {}
  TagMemoryChunk copy() const {
    TagMemoryChunk ret;
    ret.m_cap  = m_cap;
    ret.m_size = m_size;
    ret.m_data.reset(new std::byte[m_cap]);
    memcpy(ret.m_data.get(), m_data.get(), m_size);
    return ret;
  }
  std::byte *data() const { return m_data.get(); }
  bool operator==(TagMemoryChunk const &rhs) const { return rhs.m_size == m_size && 0 == memcmp(rhs.m_data.get(), m_data.get(), m_size); }
  size_t size() const { return m_size; }
};

struct ByteArrayTag : Tag {
  /// @symbol _ZTV12ByteArrayTag
  static void **vt;

  TagMemoryChunk value;
  virtual void write(IDataOutput &) const;
  virtual void load(IDataInput &);
  virtual mcpe::string toString() const;
  virtual int getId() const;
  virtual bool equals(Tag const &) const;
  virtual std::unique_ptr<Tag> copy() const;
};

struct CompoundTag : Tag {
  /// @symbol _ZTV11CompoundTag
  static void **vt;

  std::map<mcpe::string, std::unique_ptr<Tag>> value;
  virtual void write(IDataOutput &) const;
  virtual void load(IDataInput &);
  virtual mcpe::string toString() const;
  virtual int getId() const;
  virtual bool equals(Tag const &) const;
  virtual void print(mcpe::string const &, PrintStream &) const;
  virtual std::unique_ptr<Tag> copy() const;
};

struct ListTag : Tag {
  /// @symbol _ZTV7ListTag
  static void **vt;

  std::vector<std::unique_ptr<Tag>> value;
  size_t unk;
  virtual void deleteChildren();
  virtual void write(IDataOutput &) const;
  virtual void load(IDataInput &);
  virtual mcpe::string toString() const;
  virtual int getId() const;
  virtual bool equals(Tag const &) const;
  virtual void print(mcpe::string const &, PrintStream &) const;
  virtual std::unique_ptr<Tag> copy() const;
};

struct FloatTag : Tag {
  /// @symbol _ZTV8FloatTag
  static void **vt;

  float value;
  virtual void write(IDataOutput &) const;
  virtual void load(IDataInput &);
  virtual mcpe::string toString() const;
  virtual int getId() const;
  virtual bool equals(Tag const &) const;
  virtual std::unique_ptr<Tag> copy() const;
};

struct ByteTag : Tag {
  /// @symbol _ZTV7ByteTag
  static void **vt;

  unsigned char value;
  virtual void write(IDataOutput &) const;
  virtual void load(IDataInput &);
  virtual mcpe::string toString() const;
  virtual int getId() const;
  virtual bool equals(Tag const &) const;
  virtual std::unique_ptr<Tag> copy() const;
};

struct ShortTag : Tag {
  /// @symbol _ZTV8ShortTag
  static void **vt;

  short value;
  virtual void write(IDataOutput &) const;
  virtual void load(IDataInput &);
  virtual mcpe::string toString() const;
  virtual int getId() const;
  virtual bool equals(Tag const &) const;
  virtual std::unique_ptr<Tag> copy() const;
};

struct Int64Tag : Tag {
  /// @symbol _ZTV8Int64Tag
  static void **vt;

  int64_t value;
  virtual void write(IDataOutput &) const;
  virtual void load(IDataInput &);
  virtual mcpe::string toString() const;
  virtual int getId() const;
  virtual bool equals(Tag const &) const;
  virtual std::unique_ptr<Tag> copy() const;
};

struct IntArrayTag : Tag {
  /// @symbol _ZTV11IntArrayTag
  static void **vt;

  TagMemoryChunk value;
  virtual void write(IDataOutput &) const;
  virtual void load(IDataInput &);
  virtual mcpe::string toString() const;
  virtual int getId() const;
  virtual bool equals(Tag const &) const;
  virtual std::unique_ptr<Tag> copy() const;
};

struct IntTag : Tag {
  /// @symbol _ZTV6IntTag
  static void **vt;

  int32_t value;
  virtual void write(IDataOutput &) const;
  virtual void load(IDataInput &);
  virtual mcpe::string toString() const;
  virtual int getId() const;
  virtual bool equals(Tag const &) const;
  virtual std::unique_ptr<Tag> copy() const;
};

struct StringTag : Tag {
  /// @symbol _ZTV9StringTag
  static void **vt;

  mcpe::string value;
  virtual void write(IDataOutput &) const;
  virtual void load(IDataInput &);
  virtual mcpe::string toString() const;
  virtual int getId() const;
  virtual bool equals(Tag const &) const;
  virtual std::unique_ptr<Tag> copy() const;
};
