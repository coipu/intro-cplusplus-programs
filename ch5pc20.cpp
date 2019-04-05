// Chapter 5, Programming Challenge 20: Random Number Guessing Game
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {

	int randomNumber;  // to hold random number
	int guessNumber = 0; // to hold numbers guessed

	// get the system time
	unsigned seed = time(0);

	// seed the random number generator
	srand(seed);

	// generate random number
	randomNumber = (rand() % (100)) + 1;

	// loop to continue asking for number until found
	while (guessNumber != randomNumber)
		{
			cout << "Guess the number: ";
			cin >> guessNumber;

			if (guessNumber == randomNumber)
			{
				cout << "You guessed my number!";
				break;
			}

			if (guessNumber > randomNumber)
				cout << "Too high, try again." << endl;

			if (guessNumber < randomNumber)
				cout << "Too low, try again." << endl;
		}

	return 0;
}
