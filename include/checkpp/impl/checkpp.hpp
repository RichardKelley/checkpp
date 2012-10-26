#include "checkpp/checkpp.h"
#include "checkpp/property.h"
#include "checkpp/arbitrary.h"

#include <vector>

namespace checkpp {
  
  template<typename... Arguments>
  bool check(Property<Arguments...> p, int ct = 100) {
    
    // invalid count - probably a mistake.
    if (ct < 0) {
      return false;
    }
    
    // all instances tested return true.
    if (ct == 0) {
      return true;
    }
    
    std::vector<Result> results;
    
    for (int i = 0; i < ct; ++i) {
      // generate arbitrary data
      
      // test the data
      Result r = p(arbitrary<Arguments>(100)...);
      
      // write the result
      
    } 
  }
}
