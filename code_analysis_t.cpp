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
        request.given_url       = "";
        request.option_filename = "test.cpp";
        request.option_url      = "";
        request.option_language = "cdds";
		
	

        auto filename = analysis_filename(request);
        //assert(filename == "");
        //assert(analysis_url(request) == "");
        //assert(analysis_language(request, filename) == "");
        //assert(code_analysis(request) == false);
		
		/* Test case for ANALYSIS_URL. 
			Testing the following rules:
				4. The url is the given_url for a directory and a URL. There is an option_url, which takes precedence.
		*/
		//std::cout << "analysis_url: " << analysis_url(request) << std::endl; 
		
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
		
		
		/*This is the test case for ANALYSIS_LANGUAGE
			Testing the following rules:
			5. The language can be explicitly given as an option (option_language) and this supersedes all other language settings
		*/
		//std::cout << "analysis_language: " << analysis_language(request, filename) << std::endl;
		
		/*This is the test case for code_analysis
			Testing the following Error Handling:
				If the file extension is used to determine the language, and there is no mapping for that language, output the error message “Extension not supported”
				When the input is from standard input and a language cannot be determined, output the error message “Using stdin requires a declared language”
				All error messages are written to standard error (i.e., std::cerr), and the function should return a false boolean value.
		*/
		code_analysis(request);
		}

    return 0;
}
