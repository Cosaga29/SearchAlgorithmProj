#ifndef InputValidationFunctions_hpp
#define InputValidationFunctions_hpp

/*****************************************
* Author: Martin Edmunds
* Email: edmundsm@oregonstate.edu
* Date: 01/17/19
* Description: Validate input  for integers and integers
* within a range. Designated to work with standard input.
* The message version of the functions performs the same logic, just prints a message to standard output
******************************************/



#include <iostream>
#include <limits>
#include <cctype>
#include <string>


void clearInputStream();

int validateInput();

int validateInput(const std::string& message);

int validateInputRange(const int&, const int&);

int validateInputRange(const int&, const int&, const std::string&);

void validateInput(int*, const int&);

char validateInputYN();

char validateInputYN(const std::string&);

int validateInputGreaterThan(const int&);

int validateInputGreaterThan(const int&, const std::string&);


#endif