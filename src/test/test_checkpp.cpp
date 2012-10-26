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
      if (i > 0) 
	return i%2 >= 0;
      else 
	return true;
    }
  };

  // test property
  EXPECT_TRUE(checkpp::check(propSimple));
}

TEST(BasicTest, BarTest) {

  // declare property
  auto func = [](int i, int j) {
    return i + j == j + i;
  };
  
  // test property
  checkpp::check(checkpp::Property<int,int>{func});
}
