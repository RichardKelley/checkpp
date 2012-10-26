#ifndef PROPERTY_H
#define PROPERTY_H

#include <functional>

#include "checkpp/result.h"

namespace checkpp {
  
  enum maybe_bool {
    TRUE,
    FALSE,
    NOTHING
  };

  /*!
    A property represents a predicate that can be either true or
    false. Properties are tested by the system to yield results.

    Properties are also capable of tracking classifications and the
    arguments that were generated for the test. (These parts are still
    todos.)
    
    \author Richard Kelley    
  */
  template<typename... Arguments>
  class Property {
  private:
    // The property that we need to evaluate.
    std::function<bool(Arguments...)> prop;
    
    // We're faking the Maybe monad using this variable.
    maybe_bool valid;
    
  public:
    
    /*!
      Create an empty, invalid property.
    */
  Property()
    : prop{[](){}}
    , valid{NOTHING} { }

    /*!
      Create a property that uses the given predicate.
    */
  Property(std::function<bool(Arguments...)> prop_)
    : prop{prop_}
    , valid{TRUE} { }
    
    /*!
      Copy constructor.
    */
  Property(const Property& other)
    : prop{other.prop}
    , valid{TRUE} {    }

    /*
      We evaluate the predicate represented by this property by
      calling the function call operator.
    */
    Result operator()(Arguments...);

    void setValid(maybe_bool b) {
      valid = b;
    }
    maybe_bool getValid() const {
      return valid;
    }
  };
  
  /*!
    Determine the validity of this property based on the predicate
    that evaluates to the first argument.
  */
  template <typename... Arguments>
  Property<Arguments...> operator>>(const bool b, Property<Arguments...> p) {
    p.setValid(b ? TRUE : FALSE);
    return p;
  }

} // namespace checkpp

#include "impl/property.hpp"

#endif // PROPERTY_H
