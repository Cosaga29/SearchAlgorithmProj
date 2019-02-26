#include "BinarySearch.hpp"

/*
Binary search function that searches a sorted array for a value

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
int binarySearch(int* arr, int size, int toFind) {
	if (size == 0) {
		return -1;
	}

	return bSearch(arr, 0, size - 1, toFind);
}