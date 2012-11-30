#include "checkpp/checkpp.h"
#include "checkpp/property.h"
#include "checkpp/arbitrary.h"
#include "checkpp/condition.h"

#include <iostream>
#include <vector>

/*!
  Implementation for main check functions.

  \author Richard Kelley
*/

namespace checkpp {
  
  template<typename... Arguments>
  bool check(Property<Arguments...> p, int ct = 100) {
    if (ct <= 0) {
      return true;
    }

    size_t sz = 10;
    float progress = 0.0f;
    float deltaProgress = 0.0f;
    std::vector<Result> results;

    for (int i = 0; i < ct; ++i) {
      /*
	Incrementally increase the size of the inputs.	
	TODO - Replace this with something that is less ad-hoc.
      */
      progress = (float)i/(float)ct;
      if (progress - deltaProgress > .1) {
	deltaProgress += .1;
	sz *= 10;
      }
      Result r = p(arbitrary<Arguments>(sz)...);
      results.push_back(r);
    }
    bool passed = summarize(results);
    return passed;
  }

  /*!
    Check a property in the presence of a condition.
  */
  template<typename... Arguments> 
  bool check(Condition<Arguments...> c, int ct = 1000) {
    if (ct <= 0) {
      return true;
    }
    
    size_t sz = 10;
    float progress = 0.0f;
    float deltaProgress = 0.0f;
    int successfulAttempts = 0;
    
    std::vector<Result> results;
    for (int i = 0; i < ct; ++i) {
      /*
	Incrementally increase the size of the inputs.
	TODO - Replace this with something that is less ad-hoc.
      */
      progress = (float)i/(float)ct;
      if (progress - deltaProgress > .1) {
	deltaProgress += .1;
	sz *= 10;
      }
      
      Result r = c.evaluate(arbitrary<Arguments>(sz)...);
      
      /*
	Break out of testing if we succeed 100 times.
	TODO replace 100 with a user-settable parameter.
      */
      if (r.getValid() && r.getOk()) {
	successfulAttempts++;
	if (successfulAttempts == 100) {
	  results.push_back(r);
	  break;
	}
      }
      
      results.push_back(r);
    }
    bool passed = summarize(results);
    return passed;    
  }

} // namespace checkpp
