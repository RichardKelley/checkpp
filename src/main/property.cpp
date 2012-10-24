#include "checkpp/property.h"

template <typename... Arguments>
bool checkpp::Property<Arguments...>::operator()(Arguments... args) {
  return prop(args...);
}
