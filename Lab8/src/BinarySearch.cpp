/*****************************************************
Author: Martin Edmunds
Assignment: Lab 8
Date: 02/27/19
Description:

Defines functions for binary search functions. Includes
a recursive search binary search and an iterative binary search
function.

******************************************************/

#include "BinarySearch.hpp"


/*
Iterative binary search that halfs the array each iteration until 1 value remains, or the value is found

Param:
	arr - array to be searched
	size - size of array
	value - value to be searched for


Return:
	int - index of the result if found, -1 otherwise
*/
int binarySearch(int* arr, const int size, const int value) {
	int low = 0;			//low index
	int high = size - 1;	//high index

	//while there is 1 or more elements
	while (low <= high) {
		int mid = (low + high) / 2;

		if (arr[mid] == value) {
			return mid;
		}

		//search lower half
		else if (arr[mid] > value) {
			high = mid - 1;
		}

		//search higher half
		else {
			low = mid + 1;
		}
	}

	//value not found
	return -1;

}


/*
Iterative binary search that halfs the array each iteration until 1 value remains, or the value is found

Param:
	arr - array to be searched
	size - size of array
	value - value to be searched for


Return:
	int - index of the result if found, -1 otherwise
*/
int bSearch(int* arr, int lowIndex, int highIndex, int toFind) {

	//check if low index = high index, if so, then array size cannot be reduced any further
	if (lowIndex == highIndex) {
		if (arr[lowIndex] == toFind) {
			return lowIndex;
		}
		else {
			return -1;
		}
	}

	//binary search top/bottom
	int midIndex = (highIndex + lowIndex) / 2;	//calculate midpoint of array
	if (arr[midIndex] == toFind) {	//check case if midpoint index is chosen
		return midIndex;
	}

	if (arr[midIndex] > toFind) {	//if value at mid is greater than searched value, search all values less than (low - mid)
		return bSearch(arr, lowIndex, midIndex, toFind);
	}
	else {							//if value at mid is less than searched value, search all values greater than it (mid - high)
		return bSearch(arr, midIndex + 1, highIndex, toFind);
	}

}

/*
Helper function that takes array, size, and value and returns search index

Param:
	arr - array to be searched
	size - size of array
	toFind - number to search for

Return:
	returns the value of the binary search (-1 if not found, otherwise index of found value)
*/
int RecursiveBinarySearch(int* arr, int size, int toFind) {
	if (size == 0) {
		return -1;
	}

	return bSearch(arr, 0, size - 1, toFind);
}