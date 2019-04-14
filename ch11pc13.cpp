// Chapter 11, Programming Challenge 13: Drink Machine Simulator
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// constant for array size (number of drinks)
const int NUM_DRINKS = 5;

// structure declaration
struct DrinkMachine
{
	string drinkName;
	double drinkCost;
	int numberDrinks;
};

// function prototype
void chooseDrink(DrinkMachine[], int);

int main()
{
	// array of structures initialized
	DrinkMachine drinks[NUM_DRINKS] = {
						{"Cola", .75, 20},
						{"Root Beer", .75, 20},
						{"Lemon-Lime", .75, 20},
						{"Grape Soda", .80, 20},
						{"Cream Soda", .80, 0},
	};

	// variable for user choice
	int userChoice;
	double totalDrinkCosts = 0;

	cout << "Drink Machine Simulator" << endl;

	do
	{
		// display contents of array as menu choices
		cout << "\n";
		for (int count = 0; count < NUM_DRINKS; count++)
		{
			cout << "#" << (count + 1);
			cout << " " << drinks[count].drinkName;
			cout << ", Cost: $" << setprecision(2) << fixed << drinks[count].drinkCost;
			cout << ", Drinks Available: " << drinks[count].numberDrinks << endl;
		}

		// get user choice
		cout << "\nEnter 0 to quit, or choose a drink number: ";
		cin >> userChoice;

		// validate user choice
		if (userChoice < 0 || userChoice > NUM_DRINKS)
		{
			cout << "\nInvalid choice. Please enter 0 to quit, or choose a drink number: ";
			cin >> userChoice;
		}

		// if user wants to quit, break out of loop
		if (userChoice == 0)
		{
			cout << "\nYou have chosen to quit." << endl;
			break;
		}
		// display message if drink chosen is sold out and start loop again
		else if (drinks[userChoice - 1].numberDrinks == 0)
		{
			cout << "\nSorry, that drink is sold out. Make another selection:" << endl;
			continue;
		}
		// call function
		else if (userChoice != 0) {
			chooseDrink(drinks, userChoice - 1);
		}

		// subtract one from number of current drink
		drinks[userChoice - 1].numberDrinks -= 1;

		// add up costs for drinks
		totalDrinkCosts += drinks[userChoice - 1].drinkCost;

	} while (userChoice != 0);

// display total amount of money the machine earned
	cout << "\nThe machine earned: $" << setprecision(2) << fixed << totalDrinkCosts << endl;

	return 0;
}

// *************************************************
// function for processing choice of drink
// ************************************************
void chooseDrink(DrinkMachine drinks[], int choice)
{

	// variables
	double amountInserted;

	// get user input for amount of money to be inserted
	cout << "\nEnter amount of money you are inserting into machine: ";
	cin >> amountInserted;

	// input validation (NO negative numbers or > 1.00)
	if (amountInserted < 0 || amountInserted > 1)
	{
		cout << "\nPlease enter a value that is more than $0.00 and but not more than $1.00: ";
		cin >> amountInserted;
	}

	// make sure user enters enough money
	if (amountInserted < drinks[choice].drinkCost)
	{
		cout << "\nPlease enter at least $" << setprecision(2) << fixed << drinks[choice].drinkCost << ". Enter new amount: ";
		cin >> amountInserted;
	}

	// display change to be returned
	cout << "\nEnjoy your pop! Your change is: $" << setprecision(2) << fixed << amountInserted - drinks[choice].drinkCost << endl;

}
