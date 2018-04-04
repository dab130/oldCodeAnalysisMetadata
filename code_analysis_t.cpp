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
        request.given_url       = "blah blah.com";
        request.option_filename = "";
        request.option_url      = "more on the blah.com";
        request.option_language = "";
		
	

        auto filename = analysis_filename(request);
        //assert(filename == "");
        //assert(analysis_url(request) == "");
        //assert(analysis_language(request, filename) == "");
        //assert(code_analysis(request) == false);
		
		/* Test case for ANALYSIS.URL. 
			Testing the following rules:
				4. The url is the given_url for a directory and a URL. There is an option_url, which takes precedence.
		*/
		std::cout << "analysis_url: " << analysis_url(request) << std::endl; 
		
		/*This test case is for ANALYSIS_FILENAME
			Testing the following rules:
				1. Option_filename supersedes any other way
				2. Given_filename is the name on the disk, for a source-code archive the entry_filename is used instead.
				3. Entry_filename = "data" then use given_filename
				7. The given_filename is a single dash “-” when the input is from standard input. In this case, the option_filename 
				and entry_filename must be used. Note that the entry_filename is not valid (i.e, “data”) for a non source code archive, 
				and the option_filename must be used. If the option_filename is blank (i.e., “”), then the resulting filename is blank, 
				and the language is based on the option_language.
		*/
		//std::cout << "analysis_filename: " << analysis_filename(request) << std::endl;
		
		
		/*This is the test case for ANALYSIS_LANGUAGE*/
		//std::cout << "analysis_language: " << analysis_language(request, filename) << std::endl;
		
		/*This is the test case for code_analysis*/
		//code_analysis(request);
		}

    return 0;
}
