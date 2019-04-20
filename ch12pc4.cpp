// Chapter 12, Programming Challenge 4: Tail Program
#include <iostream>
#include <string>
#include <cstdlib>    // exit function
#include <fstream>    // ifstream
using namespace std;

int main()
{
	string name;       // holds a file name
	string inputLine;  // holds line of input
	int lines = 0;     // counter for line numbers
	int skiplines;		// to get to last ten lines
	ifstream file;     // file stream object

	// get name of file
	cout << "Enter the file name: ";
	getline(cin, name);

	// open file
	file.open(name);

	// test for errors
	if (!file)
	{
		cout << "Error opening " << name << endl;
		exit(EXIT_FAILURE);
	}

	// count the number of lines in file
	while (!file.eof())
	{
		// get line and increment counter
		getline(file, inputLine, '\n');

		// increment line counter
		lines++;
	}

	// close file
	file.close();

	// reopen file
	file.open(name);

	// determine how many lines to skip over
	if (lines < 10)
		skiplines = 0;		// no need to skip if less than 10 lines total
	else
		skiplines = lines - 10;

	// loop to skip lines before 10
	for (int i = 0; i < skiplines; i++)
		getline(file, inputLine, '\n');

	// display last 10 lines
	while (!file.eof())
	{
		// get each line
		getline(file, inputLine, '\n');

		// display line
		cout << inputLine << endl;
	}


	// if file has less than 10 lines
	if (lines < 10)
		cout << "\nThe entire file has been displayed.\n";

	// close file
	file.close();

	return 0;
}
