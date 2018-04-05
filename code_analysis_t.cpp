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
        request.option_filename = "";
        request.option_url      = "";
        request.option_language = "";
		
        auto filename = analysis_filename(request);
        assert(filename == "");
        assert(analysis_url(request) == "");
        assert(analysis_language(request, filename) == "");
        assert(code_analysis(request) == false);
		
	}
	{	
		// Test case: analysis_url
		// The url is the given_url for a directory and a URL. There is an option_url, which takes precedence.
		analysis_request request;
		request.given_filename  = "";
        request.entry_filename  = "";
        request.given_url       = "";
        request.option_filename = "";
        request.option_url      = "www.google.com";
        request.option_language = "";
		
		auto filename = analysis_filename(request);
		assert(filename == "");
        assert(analysis_url(request) == "www.google.com");
        assert(analysis_language(request, filename) == "");
        assert(code_analysis(request) == false);
	}
	{
		//Test case: analysis_language
		//The language can be explicitly given as an option (option_language) and this supersedes all other language settings
		analysis_request request;
		request.given_filename  = "";
        request.entry_filename  = "";
        request.given_url       = "";
        request.option_filename = "";
        request.option_url      = "";
        request.option_language = "c++";
		
		auto filename = analysis_filename(request);
		assert(filename == "");
        assert(analysis_url(request) == "");
        assert(analysis_language(request, filename) == "c++");
        assert(code_analysis(request) == false);
	}
	{
		//Test case: analysis_language
		//The language is based on the file extension. The completed, provided function, get_language_from_filename(), is used for this.
		//This is a pass test case that will return 
		analysis_request request;
		request.given_filename  = "";
        request.entry_filename  = "";
        request.given_url       = "";
        request.option_filename = "test.cpp";
        request.option_url      = "";
        request.option_language = "";
		
		auto filename = analysis_filename(request);
		filename = analysis_filename(request);
        assert(analysis_url(request) == "");
       // assert(analysis_language(request, filename) == "C++");
        assert(code_analysis(request) == false);
	}	
    return 0;
}
