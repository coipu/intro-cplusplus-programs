// Chapter 9, Programming Challenge 11: Array Expander
#include <iostream>
using namespace std;

// function protoype
int *twiceArray(int *, int);

int main()
{
	// define array size and initialize array
	const int SIZE = 3;
	int arr[SIZE] = { 2, 4, 6 };
	int *newArray = nullptr;	 // pointer to new array that is 2x size

	// call function that doubles the size of first array
	newArray = twiceArray(arr, SIZE);

	// print original array
	cout << "Original array: \n";
	for (int i = 0; i < SIZE; i++)
		cout << arr[i] << endl;

	// print new array
	cout << "New array: \n";
	for (int i = 0; i < (SIZE * 2); i++)
		cout << newArray[i] << endl;

	// free the memory and set pointer to 0
	delete[] newArray;
	newArray = nullptr;

	return 0;
}

// **************************************************
// Function to double the size of the original array.

int *twiceArray(int *arr, int SIZE)
{
	// allocate new array that is twice as big
	int *twiceArray = new int[SIZE * 2];

	// copy array's contents to the new array
	for (int i = 0; i < SIZE; i++)
		twiceArray[i] = arr[i];

	// initialize the unused elements of the second array with 0
	for (int i = SIZE; i < SIZE * 2; i++)
		twiceArray[i] = 0;

	// return pointer to new array
	return twiceArray;
}
