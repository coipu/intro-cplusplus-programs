// Chapter 10, Programming Challenge 17: Morse Code Converter (using switch statement)
#include <iostream>
#include <string>

using namespace std;

// function prototype
string morseCode(char);

int main()
{
    string userString, conversion;

    cout << "Enter text to convert into Morse code. Only use letters, numbers, spaces," << endl;
	  cout << "commas, periods, or question marks: "<< endl;
    getline(cin,userString);

    for(int i = 0; i < userString.length(); i++ )
    {
        conversion += morseCode(userString[i]);
    }

    // print out original text and Morse code
	cout << "\n" << userString << " in Morse code is " << conversion << endl;

    return 0;
}

// function to find morse code for each letter/number/etc. input
string morseCode(char alphanum)
{
	string morse;
	switch(toupper(alphanum))  // change lowercase letters to uppercase
	{
    case ' ' : morse = " "; break;
    case ',' : morse = "--..--"; break;
		case '.' : morse = ".-.-.-"; break;
		case '?' : morse = "..--.."; break;
    case '0' : morse = "-----"; break;
		case '1' : morse = ".----"; break;
		case '2' : morse = "..---"; break;
		case '3' : morse = "...--"; break;
		case '4' : morse = "....-"; break;
		case '5' : morse = ". ..."; break;
		case '6' : morse = "-...."; break;
		case '7' : morse = "--..."; break;
		case '8' : morse = "---.."; break;
		case '9' : morse = "----."; break;
		case 'A' : morse = ".-"; break;
		case 'B' : morse = "-..."; break;
		case 'C' : morse = "-.-."; break;
		case 'D' : morse = "-.."; break;
		case 'E' : morse = "."; break;
		case 'F' : morse = "..-."; break;
    case 'G' : morse = "--."; break;
		case 'H' : morse = "...."; break;
		case 'I' : morse = ".."; break;
		case 'J' : morse = ".---"; break;
		case 'K' : morse = "-.-"; break;
		case 'L' : morse = ".-.."; break;
		case 'M' : morse = "--"; break;
		case 'N' : morse = "-."; break;
		case 'O' : morse = "---"; break;
		case 'P' : morse = ".--."; break;
    case 'Q' : morse = "--."; break;
		case 'R' : morse = ".-."; break;
		case 'S' : morse = "..."; break;
		case 'T' : morse = "-"; break;
		case 'U' : morse = "..-"; break;
		case 'V' : morse = "...-"; break;
		case 'W' : morse = ".--"; break;
		case 'X' : morse = "-.."; break;
		case 'Y' : morse = "-.-"; break;
		case 'Z' : morse = "--."; break;
		
		default : morse = "Unknown";
	};

    return morse;
}
