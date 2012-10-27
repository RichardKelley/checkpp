/*
  Tests for the main code in checkpp.
  
  \author Richard Kelley
*/

#include <iostream>

#include "checkpp/checkpp.h"
#include "gtest/gtest.h"

#include "checkpp/arbitrary.h"

// for testing user-defined arbitraries.


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

class IntWrapper {
  int i;
public:
  IntWrapper(int i_) 
    : i{i_} { }

  int value() const {
    return i;
  }
};

// mildly annoying syntax, but we can easily generate arbitraries this
// way.
namespace checkpp {
  template<> IntWrapper arbitrary<IntWrapper>(size_t sz) {
    return IntWrapper{checkpp::arbitrary<int>(sz)};
  }
}
TEST(CustomTest, IntWrapperTest) {
  checkpp::Property<IntWrapper> wrapperProp {
    [](IntWrapper iw) {
      return iw.value() >= 0 || iw.value() < 0;
    }
  };

  EXPECT_TRUE(checkpp::check(wrapperProp));  
}
