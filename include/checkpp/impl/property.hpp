#include "checkpp/property.h"
#include "checkpp/result.h"

template <typename... Arguments>
checkpp::Result checkpp::Property<Arguments...>::operator()(Arguments... args) {
  checkpp::Result r{};
  if (valid) {
    r.setOk(prop(args...));
    r.setValid(true);
  } 
  return r;
}
