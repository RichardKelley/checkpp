#include "arbitrary.h"

#include <type_traits>
#include <random>
#include <unistd.h>

namespace checkpp {

  template <typename T>
  T arbitrary_arith(std::true_type, size_t sz) {
    T val;
    
    if (std::is_signed<T>::value) {
      std::uniform_int_distribution<T> u(-sz, sz);
      val = u(rng());
    } else { 
      std::uniform_int_distribution<T> u(0, sz);
      val = u(rng());
    }
    return val;
  }

  template <typename T>
  T arbitrary_arith(std::false_type, size_t sz) {
    std::uniform_real_distribution<T> u(-sz, sz);
    return u(rng());
  }

  template <typename T>
  T arbitrary(size_t sz) {
    if (std::is_arithmetic<T>::value) {
      return arbitrary_arith<T>(std::is_integral<T>(), sz);
    }
  }

  template<> bool arbitrary<bool>(size_t sz) {
    std::bernoulli_distribution b;
    return b(rng());
  }

  template<> char arbitrary<char>(size_t sz) {
    std::uniform_int_distribution<char> u;
    return u(rng());
  }


}
