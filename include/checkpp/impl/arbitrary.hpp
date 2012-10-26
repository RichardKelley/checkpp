#include "checkpp/arbitrary.h"

#include <type_traits>
#include <random>
#include <unistd.h>

namespace checkpp {

  //std::mt19937 rng(time(NULL));

  template <typename T>
  T arbitrary_arith(std::true_type, size_t sz) {
    T val;
    
    //std::mt19937 rng(time(NULL));

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
    //std::mt19937 rng(time(NULL));
    std::uniform_real_distribution<T> u(-sz, sz);
    return u(rng());
  }

  template <typename T>
  T arbitrary(size_t sz) {
    //std::mt19937 rng(time(NULL));
    if (std::is_arithmetic<T>::value) {
      return arbitrary_arith<T>(std::is_integral<T>(), sz);
    }
  }
}
