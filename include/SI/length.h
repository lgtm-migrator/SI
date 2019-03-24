#pragma once
#include <limits>
#include <ratio>
#include <stdexcept>

#include "detail/unit.h"

namespace SI {
/// @todo add astronomic units
template <typename _Type, typename _Ratio>
using length_t = detail::unit_t<'L', 1, _Type, _Ratio>;

template <typename _Type> using atto_meter_t = length_t<_Type, std::atto>;
template <typename _Type> using femto_meter_t = length_t<_Type, std::femto>;
template <typename _Type> using pico_meter_t = length_t<_Type, std::pico>;
template <typename _Type> using nano_meter_t = length_t<_Type, std::nano>;
template <typename _Type> using micro_meter_t = length_t<_Type, std::micro>;
template <typename _Type> using milli_meter_t = length_t<_Type, std::milli>;
template <typename _Type> using centi_meter_t = length_t<_Type, std::centi>;
template <typename _Type> using meter_t = length_t<_Type, std::ratio<1>>;
template <typename _Type> using kilo_meter_t = length_t<_Type, std::kilo>;
template <typename _Type> using mega_meter_t = length_t<_Type, std::mega>;
template <typename _Type> using giga_meter_t = length_t<_Type, std::giga>;
template <typename _Type> using tera_meter_t = length_t<_Type, std::tera>;
template <typename _Type> using peta_meter_t = length_t<_Type, std::peta>;
template <typename _Type> using exa_meter_t = length_t<_Type, std::exa>;

inline namespace literals {
template <char... _Digits> constexpr auto operator""_am() {
  return SI::detail::check_overflow<atto_meter_t<int64_t>, _Digits...>();
}

template <char... _Digits> constexpr auto operator""_fm() {
  return SI::detail::check_overflow<femto_meter_t<int64_t>, _Digits...>();
}

template <char... _Digits> constexpr auto operator""_pm() {
  return SI::detail::check_overflow<pico_meter_t<int64_t>, _Digits...>();
}

template <char... _Digits> constexpr auto operator""_nm() {
  return SI::detail::check_overflow<nano_meter_t<int64_t>, _Digits...>();
}

template <char... _Digits> constexpr auto operator""_um() {
  return SI::detail::check_overflow<micro_meter_t<int64_t>, _Digits...>();
}

template <char... _Digits> constexpr auto operator""_mm() {
  return SI::detail::check_overflow<milli_meter_t<int64_t>, _Digits...>();
}

template <char... _Digits> constexpr auto operator""_cm() {
  return SI::detail::check_overflow<centi_meter_t<int64_t>, _Digits...>();
}

template <char... _Digits> constexpr auto operator""_m() {
  return SI::detail::check_overflow<meter_t<int64_t>, _Digits...>();
}

template <char... _Digits> constexpr auto operator""_km() {
  return SI::detail::check_overflow<kilo_meter_t<int64_t>, _Digits...>();
}

template <char... _Digits> constexpr auto operator""_Mm() {
  return SI::detail::check_overflow<mega_meter_t<int64_t>, _Digits...>();
}

template <char... _Digits> constexpr auto operator""_Gm() {
  return SI::detail::check_overflow<giga_meter_t<int64_t>, _Digits...>();
}

template <char... _Digits> constexpr auto operator""_Tm() {
  return SI::detail::check_overflow<tera_meter_t<int64_t>, _Digits...>();
}

template <char... _Digits> constexpr auto operator""_Pm() {
  return SI::detail::check_overflow<peta_meter_t<int64_t>, _Digits...>();
}

template <char... _Digits> constexpr auto operator""_Em() {
  return SI::detail::check_overflow<exa_meter_t<int64_t>, _Digits...>();
}

constexpr auto operator""_am(long double value) {
  return atto_meter_t<long double>{value};
}

constexpr auto operator""_fm(long double value) {
  return femto_meter_t<long double>{value};
}

constexpr auto operator""_pm(long double value) {
  return pico_meter_t<long double>{value};
}

constexpr auto operator""_nm(long double value) {
  return nano_meter_t<long double>{value};
}

constexpr auto operator""_um(long double value) {
  return micro_meter_t<long double>{value};
}

constexpr auto operator""_mm(long double value) {
  return milli_meter_t<long double>{value};
}

constexpr auto operator""_cm(long double value) {
  return centi_meter_t<long double>{value};
}

constexpr auto operator""_m(long double value) {
  return meter_t<long double>{value};
}

constexpr auto operator""_km(long double value) {
  return kilo_meter_t<long double>{value};
}

constexpr auto operator""_Mm(long double value) {
  return mega_meter_t<long double>{value};
}

constexpr auto operator""_Gm(long double value) {
  return giga_meter_t<long double>{value};
}

constexpr auto operator""_Tm(long double value) {
  return tera_meter_t<long double>{value};
}

constexpr auto operator""_Pm(long double value) {
  return peta_meter_t<long double>{value};
}

constexpr auto operator""_Em(long double value) {
  return exa_meter_t<long double>{value};
}
} // namespace literals
} // namespace SI
