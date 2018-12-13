#pragma once

#include <minecraft/UUID.h>
#include <stone/operator.h>

#include <tuple>

inline static const auto UUIDStr       = utils::makeOperator(&mce::UUID::asString);
inline static const auto StdStr        = utils::makeOperator(&mcpe::string::std);
inline static const auto FloatToDouble = utils::makeOperator(+[](float const &x) -> double { return x; });
template <typename T> inline static constexpr auto EqualsTo(T target) {
  return utils::makeOperator<std::function<bool(T const &source)>>([&](auto source) { return source == target; });
}