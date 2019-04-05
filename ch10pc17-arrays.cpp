// Chapter 10, Programming Challenge 17: Morse Code Converter (using arrays)
#include <iostream>
#include <cctype>
#include <string>
using namespace std;

// initialize arrays
char englishText[40] = { ' ', ',', '.', '?', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

string morseCode[40] = { " ", "--..--", ".-.-.-", "..--..", "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--....", "---..", "----.", ".-", "-...", "-.-.","-..",".","..-","--.","....","..",".---","-.-",".-..","--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };

int main()
{
	string userString, upperString, conversion;

	// get user input
	cout << "Enter text to translate into Morse code. Only use letters, numbers, spaces," << endl;
	cout << "commas, periods, or question marks: " << endl;
	getline(cin, userString);

	// to change lowercase letters to uppercase
	for (int i = 0; i < userString.length(); i++)
		upperString += toupper(userString[i]);

	// go through each character of user input text
	for (int i = 0; i < upperString.length(); i++)
		// check for matches between two arrays
		for (int j = 0; j < 40; j++)
		{
			// if same character is found in user input and englishText
			if (upperString[i] == englishText[j])
				// get character at same position in morseCode
				conversion += morseCode[j];
		}

	// print out original text and Morse code
	cout << "\n" << userString << " in Morse code is " << conversion << endl;

	return 0;
}
