#include "checkpp/checkpp.h"
#include "checkpp/property.h"
#include "checkpp/arbitrary.h"

#include <iostream>
#include <vector>

namespace checkpp {
  
  template<typename... Arguments>
  bool check(Property<Arguments...> p, int ct = 100) {
    // all instances tested (vacuously) return true.
    if (ct <= 0) {
      return true;
    }

    size_t sz = 10;
    float progress = 0.0f;
    float deltaProgress = 0.0f;

    std::vector<Result> results;
    for (int i = 0; i < ct; ++i) {
      // right now we use an ad hoc method for increasing size.
      progress = (float)i/(float)ct;
      if (progress - deltaProgress > .1) {
	deltaProgress += .1;
	sz *= 10;
      }
      Result r = p(arbitrary<Arguments>(sz)...);
      results.push_back(r);
    }
    // print results and tell us if we passed all tests.
    bool passed = summarize(results);
    return passed;
  }
}
