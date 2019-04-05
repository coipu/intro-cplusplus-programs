// Chapter 8, Programming Challenge 8: Search Benchmarks
#include <iostream>
using namespace std;

// function prototypes
int linearSearch(const int[], int, int);
int binarySearch(const int[], int, int);

// size of array
const int SIZE = 20;

int main()
{
	// initialize array with 20 integers
	int numlist[SIZE] = { 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40 };
	int locate = 14;		// integer to find in the array
	int linearComparison;	// to hold number of comparisons
	int binaryComparison;	// to hold number of comparisons

	// call function that uses linear search to locate one integer (variable locate)
	linearComparison = linearSearch(numlist, SIZE, locate);

	// call function that uses binary search to locate same integer
	binaryComparison = binarySearch(numlist, SIZE, locate);

	// display comparison values on screen
	cout << "Number of comparisons from linear search: " << linearComparison << endl;
	cout << "Number of comparisons from binary search: " << binaryComparison << endl;

	return 0;
}

//******************************************************************
// Function definition: linear search of array

int linearSearch(const int array[], int size, int value)
{
	int index = 0;		// used as a subscript to search the array
	int position = -1;		// to record position of search value
	bool found = false;		// flag to indicate if value was found
	int comparison = 0;		// accumulator for number of comparisons made

	while (index < size && !found)
	{
		if (array[index] == value)	// if the value is found
		{
			found = true;		// set the flag
			position = index;	// record value's subscript
		}
		index++;			// go to next element
		comparison++;			// accumulate to keep track of comparisons
	}
	return comparison;
}

// Function definition: binary search of array

int binarySearch(const int array[], int size, int value)
{
	int first = 0,			// first array element
		last = size - 1,		// last array element
		middle,			// mid point of search_
		position = -1;		// position of search value
	bool found = false;			// flag to indicate if value was found
	int comparison = 0;			// accumulator for number of comparisons made

	while (!found && first <= last)
	{
		middle = (first + last) / 2;     // calculate mid point_
		if (array[middle] == value)      // if value is found at mid
		{
			found = true;
			position = middle;
		}

		else if (array[middle] > value)  // if value is in lower half
			last = middle - 1;_
		else
			first = middle + 1;          // if value is in upper half
		comparison++;			// accumulate to keep track of comparisons
	}
	return comparison;_
}
