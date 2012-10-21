#ifndef RESULT_H
#define RESULT_H

#include <string>
#include <vector>

namespace check++ {

  /*!
    Result represents the result of running a single test.

    \author Richard Kelley
  */
  class Result {
  private:
    bool ok;
    std::vector<std::string> stamp;
    std::vector<std::string> arguments;

  public:
    Result() 
      : ok{false}
    , stamp{}
    , arguments{} { }

    Result(bool ok_)
      : ok{ok_}
    , stamp{}
    , arguments{} { }

    bool getOk() const {
      return ok;
    }

    void setOk(bool ok_) {
      ok = ok_;
    }

    // TODO - add code for stamps and arguments
    
    
  };

} // namespace check++

#endif // RESULT_H
