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

    \param p The property to check.
    \param ct The number of instances to check. Defaults to 100.

    Return true iff all instances tested return true.
  */
  template<typename... Arguments>
    bool check(Property<Arguments...> p, int ct = 100);

  template<typename... Arguments> bool 
    check(Condition<Arguments...> c, int ct = 1000);

}

#include "impl/checkpp.hpp"

#endif // CHECK++_H
