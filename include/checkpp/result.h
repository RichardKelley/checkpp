#ifndef RESULT_H
#define RESULT_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

namespace checkpp {

  /*!
    Result represents the result of running a single test.

    \author Richard Kelley
  */
  class Result {
  private:
    bool ok;

    // valid == false is how we're faking Maybe in C++.
    bool valid;

    std::vector<std::string> stamp;
    std::vector<std::string> arguments;

  public:
    Result() 
      : ok{false}
    , valid{false}
    , stamp{}
    , arguments{} { }

    Result(bool ok_)
      : ok{ok_}
    , valid{true}
    , stamp{}
    , arguments{} { }
    
    bool getOk() const {
      return ok;
    }
    void setOk(bool ok_) {
      ok = ok_;
    }
    
    bool getValid() const {
      return valid;
    }
    void setValid(bool v) {
      valid = v;
    }
    
    // TODO - add code for stamps and arguments
    
  };
  
  // summarize results.
  bool summarize(std::vector<Result> results);


} // namespace checkpp

#include "impl/result.hpp"

#endif // RESULT_H
