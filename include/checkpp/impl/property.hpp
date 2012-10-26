#include "checkpp/property.h"
#include "checkpp/result.h"

template <typename... Arguments>
checkpp::Result checkpp::Property<Arguments...>::operator()(Arguments... args) {
  checkpp::Result r{};
  if (valid == TRUE) {
    //std::cout << std::to_string(args)... << std::endl;
    r.setOk(prop(args...));
    r.setValid(true);
  }
  return r;
}
