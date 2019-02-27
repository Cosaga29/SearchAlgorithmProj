#ifndef MERGE_SORT_HPP
#define MERGE_SORT_HPP


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



void combine(int*, int*, int, int, int);

void splitAndMerge(int*, int*, int, int);

void mergeSort(int*, int);


#endif