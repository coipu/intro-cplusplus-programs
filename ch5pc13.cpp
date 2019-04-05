// Chapter 5, Programming Challenge 13: The Greatest and Least of These
#include <iostream>
using namespace std;

int main() {

	int number; // to hold numbers input by user
	int smallest, largest;  // to hold numbers determined to be smallest and largest

	// get first number and assign it to both smallest and largest
	cout << "Enter integer or -99 to stop: ";
	cin >> number;
	smallest = largest = number;

	// continue asking for numbers if first number is not -99
	while (number != -99)
	{
		cout << "Enter integer or -99 to stop: ";
		cin >> number;
		// exit out of loop to end if user inputs -99
		if (number == -99)
			break;
		// assign new smallest and largest numbers when found
		if (number < smallest)
			smallest = number;
		if (number > largest)
			largest = number;
	}

	// display largest and smallest numbers
	cout << "\nThe smallest number is: " << smallest << endl;
	cout << "The largest number is: " << largest << endl;

	return 0;
}
