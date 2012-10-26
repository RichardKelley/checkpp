/*
  Tests for the main code in checkpp.
  
  \author Richard Kelley
*/

#include <iostream>

#include "checkpp/checkpp.h"

#include "gtest/gtest.h"

TEST(BasicTest, FooTest) {
  // declare property
  checkpp::Property<int> propSimple {
    [](int i) {
      return i % 2 >= 0;
    }
  };

  // test property
  EXPECT_TRUE(checkpp::check(propSimple));
}

TEST(BasicTest, BarTest) {

  // declare property
  auto func = [](int i) -> bool {
    return i % 2 >= 0;
  };
  
  // test property
  checkpp::check(checkpp::Property<int>{func});
}
