#ifndef CHECKPP_H
#define CHECKPP_H

#include <functional>

#include "checkpp/arbitrary.h"
#include "checkpp/property.h"
#include "checkpp/result.h"

#include "checkpp/condition.h"

/*!
  Main include for checkpp.

  \author Richard Kelley
*/

namespace checkpp {

  /*!
    Check that the property specified is true for arbitrary instances
    of the input.

    If ct is non-positive, we return true (no instance checked
    returned false).

    \param p The property to check.
    \param ct The number of instances to check. Defaults to 100.

    \return true iff all instances tested return true.
  */
  template<typename... Arguments>
    bool check(Property<Arguments...> p, int ct = 100);

  /*!
    Check that the property specified (in the condition) is true for
    arbitrary instances that satisfy the condition.
  
    If ct is non-positive, we return true (no instance checked
    returned false). 
  
    \param c The condition to check.
    \param ct The number of instances to check. Defaults to 1000.

    \return true iff all instances tested return true.
  */
  template<typename... Arguments> bool 
    check(Condition<Arguments...> c, int ct = 1000);
}

#include "impl/checkpp.hpp"

#endif // CHECK++_H
