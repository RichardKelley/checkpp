#include "checkpp/arbitrary.h"

namespace checkpp {

  /*
    Fully specialized templates go here.
  */
  template<> bool arbitrary<bool>(size_t sz) {
    //std::mt19937 rng(time(NULL));
    std::bernoulli_distribution b;
    return b(rng());
  }
  
  template<> char arbitrary<char>(size_t sz) {
    //std::mt19937 rng(time(NULL));
    std::uniform_int_distribution<char> u;
    return u(rng());
  }
  
}
