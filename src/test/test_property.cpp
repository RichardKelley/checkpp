#include "checkpp/property.h"
#include "checkpp/result.h"

#include "gtest/gtest.h"

TEST(PropertyCreation, TruePredicate) {
  
  checkpp::Property<> p{ 
    [](){
      return true;
    } 
  };

  checkpp::Property<int> p_even { 
    [](int i) { 
      return i % 2 == 0;
    } 
  };

  EXPECT_TRUE(p().getOk());    
  EXPECT_FALSE(p_even(3).getOk());
  EXPECT_TRUE(p_even(42).getOk());

}

TEST(BasicConditions, ConstantPredicate) {

  checkpp::Property<> p {
    []() {
      return true;
    }
  };

  auto prop = (1==1) >> p;

  EXPECT_EQ( prop().getOk(), p().getOk());

}
