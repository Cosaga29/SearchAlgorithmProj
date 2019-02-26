#include "MergeSort.hpp"

//example: low index = 0; high index = 3 for arr[4]
void combine(int* arr, int* arrcpy, int lowIndex, int midIndex, int highIndex) {

	int i = lowIndex;				//index into lower half (starts at 0)
	int j = midIndex + 1;	//index into upper half (starts at 2)
	int k = 0;				//index into copy array (starts at 0)

	while (i <= midIndex && j <= highIndex) {	//while i < 2, and j < 4
		//compare elements 
		if (arr[i] <= arr[j]) {
			arrcpy[k] = arr[i];
			i++;
			k++;
		}
		else {
			arrcpy[k] = arr[j];
			j++;
			k++;
		}
	}


	//add remaining elements 
	while (i <= midIndex) {
		arrcpy[k] = arr[i];
		i++;
		k++;
	}
	while (j <= highIndex) {
		arrcpy[k] = arr[j];
		j++;
		k++;
	}


	//copy elements from arrcpy to arr
	for (int i = lowIndex; i <= highIndex; i++) {
		arr[i] = arrcpy[i - lowIndex];
	}



}

/*
Function that splits the fed array until 1 element is in each set

Recombines the split arrays into one sorted array
*/
void splitAndMerge(int* arr, int* arrcpy, int lowIndex, int highIndex) {


	//high index example: arr[3] = 0-2 (2-0)+1 = 3 (size)
	if (highIndex - lowIndex + 1 < 2) {
		return;	//if size of array is 1, simply return (1 element arrays are sorted)
	}

	//calculate the midpoint of the array

	//example for arr[4]: 4 - 0 = 4 / 2 = 2 (low index = 0, high index = 3, mid index = 2) arr[2] = low - 0 high - 1 mid - 0
	int midIndex = (highIndex + lowIndex) / 2;

	splitAndMerge(arr, arrcpy, lowIndex, midIndex);  // will sort from 0 - 1
	splitAndMerge(arr, arrcpy, midIndex + 1, highIndex); //will sort from  2 - 3
	combine(arr, arrcpy, lowIndex, midIndex, highIndex);	//combine both arrays from index 0 to index 3

}

/*
Helper function to create and manage resources for copying and sorting the array

Param:
	arr - array to be sorted
	size - number of elements of the array
*/
void mergeSort(int* arr, int size) {
	if (size == 0 || size == 1) {
		return;
	}

	int lowIndex = 0;
	int highIndex = size - 1;

	int* arrcpy = new int[size];

	splitAndMerge(arr, arrcpy, lowIndex, highIndex);

	delete[] arrcpy;
}
