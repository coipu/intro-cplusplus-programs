// Chapter 5, Programming Challenge 25: Using Files - Student Line Up
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {

	ifstream inputFile;  // file stream object
	string name;  // to hold names from file while looping through
	string front, back; // to hold names of people at front and at back of line

	// open file
	inputFile.open("C:\\Users\\jenni\\Desktop\\LineUp.txt");

	// read first name from file and assign to both front and back
	inputFile >> name;
	front = back = name;

	// continue reading names from text file until no more data to read
	while (inputFile >> name)
	{
		// compare names according to ASCII values
		if (name < front)
			front = name;
		if (name > back)
			back = name;

	}

	// close file
	inputFile.close();

	// display who will be at front and at back of line
	cout << front << " is at the front of the line." << endl;
	cout << back << " is at the back of the line." << endl;

	return 0;
}
