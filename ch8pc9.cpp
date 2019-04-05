// Chapter 8, Programming Challenge 9: Sorting Benchmarks
#include <iostream>
using namespace std;

// function prototypes
int bubbleSort(int[], int);
int selectionSort(int[], int);

// size of array
const int SIZE = 20;

int main()
{
	// initialize identical arrays with 20 integers
	int numlist1[SIZE] = { 56, 98, 34, 55, 90, 33, 25, 14, 78, 11, 3, 19, 62, 48, 81, 28, 23, 5, 18, 0 };
	int numlist2[SIZE] = { 56, 98, 34, 55, 90, 33, 25, 14, 78, 11, 3, 19, 62, 48, 81, 28, 23, 5, 18, 0 };
	int bubbleExchanges;	// to hold number bubble sort exchanges
	int selectionExchanges;	// to hold number selection sort exchanges

	// call function that uses bubble sort
	bubbleExchanges = bubbleSort(numlist1, SIZE);

	// call function that uses selection sort
	selectionExchanges = selectionSort(numlist2, SIZE);

	// display number of exchanges on screen
	cout << "Number of exchanges from bubble sort: " << bubbleExchanges << endl;
	cout << "Number of exchanges from selection sort: " << selectionExchanges << endl;

	return 0;
}

//******************************************************************
// Function definition: ascending order bubble sort of array

int bubbleSort(int array[], int size)
{
	bool swap;					// boolean flag
	int temp;					// temporary variable for swapping
	int exchanges = 0;			// accumulator for number of exchanges made

	do
	{
		// set flag to false
		swap = false;
		for (int count = 0; count < (size - 1); count++)
		{
			if (array[count] > array[count + 1])
			{
				// swap contents of array[count] and array[count + 1]
				temp = array[count];
				array[count] = array[count + 1];
				array[count + 1] = temp;
				// set flag to true
				swap = true;
			}
			// accumulate to keep track of exchanges
			exchanges++;
		}
	} while (swap);		// while any elements have been swapped


	return exchanges;
}

// Function definition: ascending order selection sort of array

int selectionSort(int array[], int size)
{
	int startScan, minIndex, minValue;
	int exchanges = 0;					// accumulator for number of exchanges made

	// nested loops to move contents of every element to their proper location
	for (startScan = 0; startScan < (size - 1); startScan++)
	{
		minIndex = startScan;
		minValue = array[startScan];

		// inner for loop searches for element with smallest value
		for (int index = startScan + 1; index < size; index++)
		{
			if (array[index] < minValue)
			{
				minValue = array[index];	// holds smallest value
				minIndex = index;			// holds subscript of smallest value
			}
		}

		// outer for loop exchanges contents of smallest element with array[startScan]
		array[minIndex] = array[startScan];
		array[startScan] = minValue;
		// accumulate to keep track of exchanges
		exchanges++;
	}
	return exchanges;
}
