#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <fstream>
#include <vector>

#include "MergeSort.hpp"
#include "BinarySearch.hpp"
#include "InputValidationFunctions.hpp"

#define NUM_COUNT 10
#define NUM_OF_FILES 4

#define log(x) std::cout << x << std::endl;



int linearSearch(int* arr, int size, int toFind);

bool isFound(int* arr, int size, int toFind, int(*)(int*, int, int));

void outputToFile(int* arr, int size, std::vector<std::string>& fileNames);


int main() {
	std::vector<std::string> userFileNameList;

	srand(time(0));

	//allocate space for storage arrays
	int arr1[NUM_COUNT];
	int arr2[NUM_COUNT];
	int arr3[NUM_COUNT];
	int arr4[NUM_COUNT];



	//Read values from files
	std::string startFile = "nums.txt";
	std::string earlyFile = "early.txt";
	std::string midFile = "mid.txt";
	std::string endFile = "end.txt";

	//open all files
	std::ifstream f1(startFile.c_str());
	std::ifstream f2(earlyFile.c_str());
	std::ifstream f3(midFile.c_str());
	std::ifstream f4(endFile.c_str());

	//create array to hold two prompts
	std::string results[2] = { "Target value not found", "Target value found" };

	//read data from file into arrays
	if (f1.good() && f2.good() && f3.good() && f4.good()) {

		//read numbers from file into array
		for (int i = 0; i < NUM_COUNT; i++) {
			f1 >> arr1[i];
			f2 >> arr2[i];
			f3 >> arr3[i];
			f4 >> arr4[i];
		}

		f1.close();
		f2.close();
		f3.close();
		f4.close();

	}


	//display linearSearch results (LINEAR SEARCH)
	std::cout << "What is the target value? " << std::endl;


	int toSearch = validateInput();
	clearInputStream();
	std::cout << startFile << ": " << results[isFound(arr1, NUM_COUNT, toSearch, &linearSearch)] << std::endl;
	std::cout << earlyFile << ": " << results[isFound(arr2, NUM_COUNT, toSearch, &linearSearch)] << std::endl;
	std::cout << midFile << ": " << results[isFound(arr3, NUM_COUNT, toSearch, &linearSearch)] << std::endl;
	std::cout << endFile << ": " << results[isFound(arr4, NUM_COUNT, toSearch, &linearSearch)] << std::endl;


	//sort arrays
	mergeSort(arr1, NUM_COUNT);
	mergeSort(arr2, NUM_COUNT);
	mergeSort(arr3, NUM_COUNT);
	mergeSort(arr4, NUM_COUNT);

	
	//output sorted arrays to files
	outputToFile(arr1, NUM_COUNT, userFileNameList);
	outputToFile(arr2, NUM_COUNT, userFileNameList);
	outputToFile(arr3, NUM_COUNT, userFileNameList);
	outputToFile(arr4, NUM_COUNT, userFileNameList);


	//output results of binary search from files outputted by the user
	std::cout << userFileNameList[0] << results[isFound(arr1, NUM_COUNT, toSearch, &binarySearch)] << std::endl;
	std::cout << userFileNameList[1] << results[isFound(arr2, NUM_COUNT, toSearch, &binarySearch)] << std::endl;
	std::cout << userFileNameList[2] << results[isFound(arr3, NUM_COUNT, toSearch, &binarySearch)] << std::endl;
	std::cout << userFileNameList[3] << results[isFound(arr4, NUM_COUNT, toSearch, &binarySearch)] << std::endl;
	


	std::cin.get();




	return 0;
}




/*
Searches through an array to find a number, returns -1 if number not found

Param:
	arr - array to linearSearch
	size - size of array
	toFine - number to fine in the array


Return:
	int - index of found number
*/
int linearSearch(int* arr, int size, int toFind) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == toFind) {
			return i;
		}
	}
	return -1;
}

bool isFound(int* arr, int size, int toFind, int(*searchFunction)(int*, int, int)) {
	if (searchFunction(arr, size, toFind) == -1) {
		return false;
	}
	else {
		return true;
	}
}


void outputToFile(int* arr, int size, std::vector<std::string>& fileNames) {

	std::string outFile;
	std::cout << "Enter a filename to output to: " << std::endl;
	std::getline(std::cin, outFile);

	std::ofstream out(outFile);
	fileNames.emplace_back(outFile);

	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
		out << arr[i];
	}

	out.close();

	std::cout << std::endl;
}
