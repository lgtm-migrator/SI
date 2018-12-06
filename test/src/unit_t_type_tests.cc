#include <catch.hpp>

#include <SI/unit.h>

using namespace SI;

TEST_CASE("GIVEN a variable of type unit_t THEN is_unit_t returns true") {
  constexpr unit_t<'X'> v1{0};
  static_assert(is_unit_t<decltype(v1)>::value == true, "is of unit type");
}

TEST_CASE("GIVEN a variable of type int THEN is_unit_t returns false") {

  constexpr int v1{0};
  static_assert(is_unit_t<decltype(v1)>::value == false, "is not of unit type");
}

TEST_CASE("GIVEN derived type derived from unit_t THEN is_unit_t returns true "
          "if casted") {

  struct to_test : unit_t<'X'> {};
  constexpr to_test v1{0};

  static_assert(
      is_unit_t<decltype(static_cast<const unit_t<'X'>>(v1))>::value == true,
      "derived type is of type unit_t");
}

TEST_CASE("GIVEN two units of the same dimension type, ratio and value WHEN "
          "cast from one to "
          "another THEN units stay the same") {
  constexpr unit_t<'X'> v1{0};

  constexpr auto result = unit_cast<decltype(v1)>(v1);
  static_assert(result == v1, "Result is same as input");
  static_assert(std::is_same<decltype(result), decltype(v1)>::value,
                "casted type is the same");
}

TEST_CASE("GIVEN two units of same dimension type and different ratio WHEN "
          "cast from one to another THEN value is according to the ratio") {
  constexpr unit_t<'X', 1, std::milli> v1{1000};
  constexpr auto result = unit_cast<unit_t<'X', 1, std::ratio<1>>>(v1);

  static_assert(std::is_same<decltype(result),
                             const unit_t<'X', 1, std::ratio<1>>>::value,
                "Casted to correct unit");
  static_assert(result.raw_value() == 1, "value adjusted for ratio");
}