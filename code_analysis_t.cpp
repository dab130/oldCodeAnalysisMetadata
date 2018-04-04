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
        request.given_filename  = "testing";
        request.entry_filename  = "data";
        request.given_url       = "";
        request.option_filename = "";
        request.option_url      = "";
        request.option_language = "";
		
	

        auto filename = analysis_filename(request);
        //assert(filename == "");
        assert(analysis_url(request) == "");
        assert(analysis_language(request, filename) == "");
        assert(code_analysis(request) == false);
		
		/* Test case for analysis_url. When given data from the struct it will choose precedence.
			This will Still fail the assertion no error handling yet...
		*/
		//std::cout << "analysis_url: " << analysis_url(request) << std::endl; 
		
		/*This test case is for analysis_filename
		*/
		std::cout << "analysis_filename: " << analysis_filename(request) << std::endl;
		
		}

    return 0;
}
