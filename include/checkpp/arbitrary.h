#ifndef ARBITRARY_H
#define ARBITRARY_H

#include <type_traits>
#include <random>
#include <unistd.h>

inline std::mt19937& rng() {
  static std::mt19937 rng(time(nullptr));
  return rng;
}

namespace checkpp {
  
  /*!
    A standard RNG. We initialize this once and share the rng in
    arbitrary instances.
  */
  //std::mt19937& rng();

  /*!
    Return an arbitrary instance of an integral type.

    The parameter passed to arbitrary is a size parameter.
  */
  template <typename T>
    T arbitrary_arith(std::true_type, size_t sz);
  
  /*!
    Return an arbitrary instance of a floating-point type.
    
    The parameter passed represents size.
  */
  template <typename T>
    T arbitrary_arith(std::false_type, size_t sz);

  /*!

    Handle all integral types except for bools and chars, using a
    uniform distribution.

    The parameter passed represents size.
  */
  template <typename T> T arbitrary(size_t sz);

  /*!
    Specialization of arbitrary for booleans.

    We use a bernoulli distribution to generate values. Because there
    are only two possible outcomes and we want a uniform distribution,
    we use the default value for p.

    The parameter passed represents size.
  */
  template<> bool arbitrary<bool>(size_t sz);

  /*!
    Specialization of arbitrary for (small) chars.

    This specialization is only for 8-bit chars. The larger char types
    appear to work just fine with the non-specialized version.

    The parameter passed represents size.
  */
  template<> char arbitrary<char>(size_t sz);
  

} // namespace checkpp

// implementations for the above declarations.
#include "impl/arbitrary.hpp"

#endif // ARBITRARY_H
