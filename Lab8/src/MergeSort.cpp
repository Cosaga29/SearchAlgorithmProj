/*****************************************************
Author: Martin Edmunds
Assignment: Lab 8
Date: 02/27/19
Description:

Defines functions for the merge sort algorithm. Consists
of combine function to merge two sorted sub arrays, and splitandmerge
function that splits the array until each sub array is of size = 1, and
defines a helper function to make usage of the merge sort algorithm easy.

******************************************************/


#include "MergeSort.hpp"

/*
Merge sort helper function that handles the combining of the two sorted array halves.

Param:
	arr- array to be combined from
	arrcpy - array to store the combined array results
	lowIndex - low index of elements to be combined
	midIndex - below mid index - 1st array, above - 2nd array
	highIndex - high index of elements to be combined

*/
void combine(int* arr, int* arrcpy, int lowIndex, int midIndex, int highIndex) {

	int i = lowIndex;				//index into lower half
	int j = midIndex + 1;	//index into upper half 
	int k = 0;				//index into copy array 

	while (i <= midIndex && j <= highIndex) {	//array indicies are valid
		//compare elements, add whichever value compares lower
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


	//add remaining elements of the array that did NOT go out of bounds from above loop
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

Param:
	arr - array to be sorted
	arrcpy - array to contain intermitant sorted elements
	lowIndex - lower sort bound
	highIndex - upper sort bound
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
Allows a user of the merge sort function to simply pass array and size without worrying about
the resources for the copied array.

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
