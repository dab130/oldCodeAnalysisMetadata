/*
  @file code_analysis_t.cpp

  Test program for analysis requests
*/

#include "code_analysis.hpp"


#include <string>
#include <cassert>
#include <iostream>

int main() {

    // all parts of the request are empty
    {
		
		
        analysis_request request;
        request.given_filename  = "";
        request.entry_filename  = "";
        request.given_url       = "given url";
        request.option_filename = "";
        request.option_url      = "option url";
        request.option_language = "";
		
	

        auto filename = analysis_filename(request);
        assert(filename == "");
        //assert(analysis_url(request) == "");
        assert(analysis_language(request, filename) == "");
        assert(code_analysis(request) == false);
		
		std::cout << "analysis_url: " << analysis_url(request) << std::endl; 
		
		}

    return 0;
}
