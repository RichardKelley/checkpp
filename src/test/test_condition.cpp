/*
  Tests for conditions in checkpp.

  \author Richard Kelley
*/

#include <iostream>

#include "checkpp/checkpp.h"
#include "checkpp/condition.h"
#include "checkpp/property.h"

#include "gtest/gtest.h"

#include <functional>

TEST(BasicTest, FooTest) {
  std::function<bool(int)> cond = [](int i) {
    return (i > 0) && (i % 2 == 0);
  };

  auto prop = checkpp::Property<int>{
    [](int i) {
      return (i+1) % 2 == 1;
    }
  };

  EXPECT_TRUE(checkpp::check(cond >> prop));

}
