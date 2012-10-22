/*!
  Test code for the arbitrary function on built-in types.

  Test cases make sure that we can generate arbitrary instances of
  built-in types, and that generated values are distributed uniformly
  (as we would expect).

  \author Richard Kelley
*/

#include <iostream>

#include "checkpp/arbitrary.h"
#include "gtest/gtest.h"

/*
  Test to ensure that the average of a reasonably large number of ints
  is small enough.

  The choice of (< 10) here is entirely arbitrary.
*/
TEST(ArbitraryInt, AverageIsSmall) {
  float sum = 0;
  size_t sz = 100;

  // sum up a bunch of arbitrary ints.
  for (int i = 0; i < 1000; ++i) {
    sum += checkpp::arbitrary<int>(sz);
  }

  EXPECT_LE(sum/1000, 10);

}

/*
  Test that each generated value is smaller than its bound.
 */
TEST(ArbitraryInt, AllValueBounded) {
  size_t sz = 1000;

  for (int i = 0; i < 1000; ++i) {
    /*
      Note that if we don't use an int here then the comparison will
      fail if arbitrary ever generates a negative number.
    */
    EXPECT_GE(int{sz},checkpp::arbitrary<int>(sz));
  }
}

/*
  Test to ensure that the average of a large number of floats is close
  to zero.
*/
TEST(ArbitraryFloat, AverageIsSmall) {
  float sum = 0.0f;
  size_t sz = 100;

  for (int i = 0; i < 1000; ++i) {
    sum += checkpp::arbitrary<float>(sz);
  }

  EXPECT_LE(sum / 1000, 10);
  
}
