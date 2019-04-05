// Chapter 6, Programming Challenge 24: Rock, Paper, Scissors Game
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// function prototypes
void showMenu();
void chooseWinner(int, int);

int main()
{
		int randomNumber;  // to hold random number
		int userChoice;    // to hold the user's choice

	do
	{
		unsigned seed = time(0);  // get the system time
		srand(seed);  // seed the random number generator
		randomNumber = (rand() % 3) + 1;  // generate random number 1, 2, or 3

		// display menu and get and display user choice
		showMenu();
		cin >> userChoice;
		if (userChoice == 1)
			cout << "\nYou have chosen rock." << endl;
		else if (userChoice == 2)
			cout << "\nYou have chosen paper." << endl;
		else if (userChoice == 3)
			cout << "\nYou have chosen scissors." << endl;

		// display computer choice
		if (randomNumber == 1)
			cout << "\nThe computer has chosen rock." << endl;
		else if (randomNumber == 2)
			cout << "\nThe computer has chosen paper." << endl;
		else if (randomNumber == 3)
			cout << "\nThe computer has chosen scissors." << endl;

	// display winner from chooseWinner function if no tie
		if (randomNumber == userChoice)
			cout << "\nYou have tied! Please play again." << endl;
		else if (randomNumber != userChoice)
		chooseWinner(randomNumber, userChoice);
	} while (randomNumber == userChoice);  // to repeat game if tie

	return 0;
}

// function definitions
void showMenu()
{
	cout << "\nLet's play Rock, Paper, Scissors!\n\n"
		<< "1. Rock\n"
		<< "2. Paper\n"
		<< "3. Scissors\n"
		<< "\n"
		<< "Enter your choice: ";
}

void chooseWinner(int randomNumber, int userChoice)
{
	if (randomNumber == 1 && userChoice == 2)
		cout << "\nPaper beats rock. You win!" << endl;
	else if (randomNumber == 1 && userChoice == 3)
		cout << "\nRock beats scissors. You lose!" << endl;
	else if (randomNumber == 2 && userChoice == 1)
		cout << "\nPaper beats rock. You lose!" << endl;
	else if (randomNumber == 2 && userChoice == 3)
		cout << "\nScissors beats paper. You win!" << endl;
	else if (randomNumber == 3 && userChoice == 1)
		cout << "\nRock beats scissors. You win!" << endl;
	else if (randomNumber == 3 && userChoice == 2)
		cout << "\nScissors beats paper. You lose!" << endl;
}
