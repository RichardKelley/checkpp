#include "checkpp/arbitrary.h"

namespace checkpp {

  /*
    Fully specialized templates go here.
  */
  template<> bool arbitrary<bool>(size_t sz) {
    std::bernoulli_distribution b;
    return b(rng());
  }
  
  template<> char arbitrary<char>(size_t sz) {
    std::uniform_int_distribution<char> u;
    return u(rng());
  }
  
}
