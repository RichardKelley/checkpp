#ifndef PROPERTY_H
#define PROPERTY_H

#include <functional>

#include "checkpp/result.h"

namespace checkpp {
  
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
    bool valid;
    
  public:
    
    /*!
      Create an empty, invalid property.
    */
  Property()
    : prop{[](){}}
    , valid{false} { }
    
    /*!
      Create a property that uses the given predicate.
    */
  Property(std::function<bool(Arguments...)> prop_)
    : prop{prop_}
    , valid{true} { }
    
    /*
      We evaluate the predicate represented by this property by
      calling the function call operator.
    */
    Result operator()(Arguments...);

    void setValid(bool b) {
      valid = b;
    }
    bool getValid() const {
      return valid;
    }
  };
  
  /*!
    Determine the validity of this property based on the predicate
    that evaluates to the first argument.
  */
  template <typename... Arguments>
  Property<Arguments...> operator>>(const bool b, Property<Arguments...> p) {
    p.setValid(b);
    return p;
  }

} // namespace checkpp

#include "impl/property.hpp"

#endif // PROPERTY_H
