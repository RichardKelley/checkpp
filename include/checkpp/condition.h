#ifndef CONDITION_H
#define CONDITION_H

#include "checkpp/result.h"

namespace checkpp {

  /*!
    Conditions allow us to test properties conditionally.
  */
  template<typename... Arguments> class Condition {
  private:
    std::function<bool(Arguments...)> condition;
    Property<Arguments...> property;
  public:
  Condition(std::function<bool(Arguments...)> cond_,
	    Property<Arguments...> prop_)
    : condition{cond_}
    , property{prop_} { }
    
    std::function<bool(Arguments...)> getCond() const {
      return condition;
    }
    Property<Arguments...> getProp() const {
      return property;
    }

    /*!
      Evaluate an arbitrary instance.
    */
    Result evaluate(Arguments...);

  };
  
  /*!
    Haskell-like syntax for creating conditions.
  */
  template <typename... Arguments> 
    Condition<Arguments...> operator>> (std::function<bool(Arguments...)> cond, 
					Property<Arguments...> prop) {
    return Condition<Arguments...>{cond, prop};
  }

}

#include "impl/condition.hpp"

#endif // CONDITION_H
