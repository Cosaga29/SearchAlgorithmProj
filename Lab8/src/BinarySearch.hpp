#ifndef BINARY_SEARCH_HPP
#define BINARY_SEARCH_HPP

/*****************************************************
Author: Martin Edmunds
Assignment: Lab 8
Date: 02/27/19
Description:

Defines functions for binary search functions. Includes
a recursive search binary search and an iterative binary search
function.

******************************************************/


int bSearch(int* arr, int lowIndex, int highIndex, int toFind);

int RecursiveBinarySearch(int* arr, int size, int toFind);

int binarySearch(int* arr, const int size, const int value);







#endif