// DID NOT RECEIVE FULL CREDIT
// Chapter 10, Programming Challenge 3: Word Counter
#include <iostream>
using namespace std;

// function prototype
int countWords(char *);

int main()
{
	const int SIZE = 1001;		// constant for array size
	char input[SIZE];			// array to hold user input

	// ask user to input a string
	cout << "Enter a string of 1,000 characters or less: ";
	cin.getline(input, SIZE);

	// display number of words in the string on the screen
	cout << "The number of words in the string is: " << countWords(input) << endl;
}

// function that accepts a pointer to a C-string as argument
// returns number of words contained in string

int countWords(char *str)
{
	// start at 1 since first word isn't preceded by a space
	int numWords = 1;

	// go through string until null character is found
	while (*str++ != '\0')
	{
		// increment number of words each time space is found
		if (*str == ' ')
			numWords++;
	}

	// return number of words
	return numWords;
}
