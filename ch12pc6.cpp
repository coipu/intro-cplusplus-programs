// Chapter 12, Programming Challenge 6: String Search
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>    // exit function
using namespace std;

int main()
{
	string name;			// holds file name
	string searchString;	// holds string to be searched for
	string lineRead;		// holds line read from file
	int count = 0;			// number of times string appeared in file
	ifstream file;			// file stream object

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

	// get string to search for
	cout << "Enter a string to search for in the file: ";
	getline(cin, searchString);

	// search for and display all lines that contain the string
	cout << "\nAll lines in file that contain the string:\n\n";
	while (!file.eof())
	{
		getline(file, lineRead);
		if (lineRead.find(searchString, 0) < lineRead.length())
		{
			cout << lineRead << endl;
			count++;
		}

	}

	// display number of times the string appeared in the file
	cout << "\nNumer of times the string appeared in file: " << count << endl;

	// close file
	file.close();

	return 0;
}
