/*****************************************
* Author: Martin Edmunds
* Email: edmundsm@oregonstate.edu
* Date: 01/17/19
* Description: Validate input  for integers and integers
* within a range. Designated to work with standard input. 
* The message version of the functions performs the same logic, just prints a message to standard output
******************************************/



#include "InputValidationFunctions.hpp"

/*
Clears the standard input stream up to the numerical limits of the stream

Inspiration taken from stack-overflow to be able to
clear any size of stream
*/
void clearInputStream(){
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return;
}

/*
Helper function for input validation:
Function prompts the user via std input and returns
when:
    -a valid entry has been given


Args:


Return:
Validated integer
*/
int validateInput(){
    int toReturn;
    while(!(std::cin >> toReturn)){
        std::cout << "Bad input." << std::endl;
        clearInputStream();
    }
    return toReturn;
}




/*
Prints a message to the console
Functions prompts the user via std input and returns

Args:
message - message to be printed to standard out

Return:
Validated integer
*/
//Same as above function, just prints a message every loop
int validateInput(const std::string & message)
{
	int toReturn;
	while (!(std::cin >> toReturn)) {
		std::cout << "Bad input.\n" << message << std::endl;
		clearInputStream();
	}
	return toReturn;
}



/*
Function designed to return a validated input withing a certain range
Function prompts the user via std input and returns
when:
	-valid entry has been given
	-number is in the correct range (low - high inclusive)



Args:
low = low bound
high = high bound

Return: 
validated integer
*/
int validateInputRange(const int& low, const int& high){
    bool valid = false;
    int toReturn;
    while(!valid){									//while input is invalid
        while(!(std::cin >> toReturn)){				//if extraction could not occur, clear the stream
            std::cout << "Bad input. " << std::endl;
            clearInputStream();
        }

        if(toReturn >= low && toReturn <= high){	//extraction occured, check if the range is valid
            valid = true;
        }
		else {
			std::cout << "Input out of range. " << std::endl;
			clearInputStream();
		}
    }
    
    return toReturn;
}



/*
Similar to above function. Prints a message upon every loop iteration.
Args:


Return:

*/
int validateInputRange(const int &low, const int &high, const std::string & message)
{
	bool valid = false;
	int toReturn;
	while (!valid) {
		std::cout << message << std::endl;
		while (!(std::cin >> toReturn)) {
			std::cout << message << std::endl;
			std::cout << "Bad input. " << std::endl;
			clearInputStream();
		}

		if (toReturn >= low && toReturn <= high) {
			valid = true;
		}
		else {
			std::cout << "Input out of range. " << std::endl;
			clearInputStream();
		}
	}

	return toReturn;
}



/*
Function to validate an entire array

Validate an input line of numbers, separated by space. The function will continue
to prompt for integers until the buffer array has been populated. If a good input stream is given, 
the array will be filled with valid integers.


Args:
buffer - array to be filled
size - size of array

Return:


*/
void validateInput(int* buffer, const int& size) {

	int input = 0;
	bool badInputFlag;

	for (int i = 0; i < size; i++) {
		badInputFlag = false;
		
		//get a number
		if (!(std::cin >> input)) { //if bad input
			std::cout << "Bad input stream. Try again. " << std::endl;
			clearInputStream();
			badInputFlag = true;
		}
		
		buffer[i] = input; //in the case of bad input this will be overwritten when the loop resets

		if (badInputFlag) {
			//if bad input, reset the counter to set buffer write position to 0
			i = -1;
		}
	}

	return;
}



/*
Validates a y/n prompt for the user

Args:


Return:
validated y/n character
*/
//Function that just validates a (Y/N) type answer, guarentees a return of y/n
char validateInputYN() {
	
	bool validInput = false;
	char input;

	while (!validInput) {

		//prompt for input
		if (!(std::cin >> input)) {
			std::cout << "Invalid Input. Try again. " << std::endl;
			clearInputStream();
		}
		else {
			if (std::tolower(input) == 'n' || std::tolower(input) == 'y') { //if user entered a N/n or Y/y, valid input
				validInput = true;
			}
			else {
				std::cout << "Invalid Input. Try again. " << std::endl;
				clearInputStream();
			}
		}
	}

	return std::tolower(input);
}




/*
Same as above function, just with a message repeated every loop

Args:


Return:

*/
//Same as above with message functionality
char validateInputYN(const std::string &message)
{

	bool validInput = false;
	char input;

	while (!validInput) {
		std::cout << message << std::endl;
		//prompt for input
		if (!(std::cin >> input)) {
			std::cout << "Invalid Input. Try again. " << std::endl;
			clearInputStream();
		}
		else {
			if (std::tolower(input) == 'n' || std::tolower(input) == 'y') {
				validInput = true;
			}
			else {
				std::cout << "Invalid Input. Try again. " << std::endl;
				clearInputStream();
			}
		}
	}

	return std::tolower(input);
}





/*
Function that validates an integer than must be greater than a certain amount

Args:
criterion - lower bound of the integer needed

Return:
validated integer

*/
int validateInputGreaterThan(const int& criterion)
{
	int userInput = 0;

	do {
		userInput = validateInput();  //get a valid number
		if (userInput <= criterion) { //if number is less than or equal : bad, prompt again
			std::cout << "Number must be larger. " << std::endl;
		}
	} while (userInput <= criterion);

	return userInput;
}





/*
Same as above, just prints a message every loop iteration
Args:


Return:

*/
int validateInputGreaterThan(const int &criterion, const std::string &message)
{
	int userInput = 0;

	do {
		std::cout << message << std::endl;
		userInput = validateInput();
		if (userInput <= criterion) {
			std::cout << "Number must be larger. " << std::endl;
		}
	} while (userInput <= criterion);

	return userInput;
}

