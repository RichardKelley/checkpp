#include "checkpp/condition.h"

#include <iostream>

template<typename... Arguments>
checkpp::Result checkpp::Condition<Arguments...>::evaluate(Arguments... args) {
  bool passed = condition(args...);
  Result r;
  if (passed) {
    r = property(args...);
  } 
  return r;
}
