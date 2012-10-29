#include "checkpp/result.h"

bool checkpp::summarize(std::vector<Result> results) {   
  std::string summary;
  int totalTests = results.size();
  int validTests = std::count_if(results.begin(), results.end(),
				 [](Result r) { return r.getValid(); });
  int passedTests = std::count_if(results.begin(), results.end(),
				  [](Result r) { return r.getOk(); });
  
  summary = "Attempted a total of " + std::to_string(totalTests) +
    " tests.\nOf these, " + std::to_string(validTests) + 
    " were executed, and\n" + std::to_string(passedTests) + " passed.";
  
  std::cout << summary << std::endl;
  
  return passedTests == validTests;
}
