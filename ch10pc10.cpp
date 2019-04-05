// Chapter 10, Programming Challenge 10: replaceSubstring Function
#include <iostream>
#include <string>
using namespace std;

// function prototype
void replaceSubstring(string, string, string);

int main()
{
	string string1 = "the dog jumped over the fence";
	string string2 = "the";
	string string3 = "that";
	replaceSubstring(string1, string2, string3);
	return 0;
}

void replaceSubstring(string string1, string string2, string string3)
{

	// iterate through string1
	for (int i = 0; i < string1.length(); i++)
	{
		// find position of string2 in string1
		int substring = string1.find(string2);
		// replace string2 (the) with string3 (that)
		if (substring != -1)    // if found
			string1.replace(substring, string2.length(), string3);
	}
	// print new string1
	cout << string1 << endl;
} 
