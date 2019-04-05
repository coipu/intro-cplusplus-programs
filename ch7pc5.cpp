// Chapter 7, Programming Challenge 5: Monkey Business
#include <iostream>
#include <iomanip>
using namespace std;

// function prototypes
void userInput();
void averageAmount();
void greatestLeast();

// declare variables and constants
const int NUM_MONKEYS = 3;				// number of monkeys
const int NUM_DAYS = 5;					// number of days
double pounds[NUM_MONKEYS][NUM_DAYS];	// array with 3 rows (monkeys) and 5 columns (days)

int main()
{
	cout << "Enter pounds of food for each monkey on each day: \n\n";
	// call functions
	userInput();
	averageAmount();
	greatestLeast();
	return 0;
}

// Function definition - user inputs data about monkeys and pounds of food per day
void userInput() {
	// nested loops to fill array with daily pounds of food eaten for each monkey
	for (int row = 0; row < NUM_MONKEYS; row++)  // go through each monkey
	{
		for (int col = 0; col < NUM_DAYS; col++)  // go through each day for each monkey
		{
			// ask user for pounds of food for each monkey on each day
			cout << "Monkey " << (row + 1) << ", Day " << (col + 1) << ": ";
			cin >> pounds[row][col];

			// input validation - no negative numbers for pounds of food eaten
			while (pounds[row][col] < 0)
			{
				cout << "Pounds must be positive. Please re-enter: ";
				cin >> pounds[row][col];
			}

		}
		cout << endl; // blank line for spacing
	}
}

// Function definition - find average amount of food per day for all monkeys
void averageAmount() {
	// calculate average for each day by summing columns
	for (int col = 0; col < NUM_DAYS; col++)
	{
		// reset accumulator for each day
		double total = 0.0;

		// sum a column
		for (int row = 0; row < NUM_MONKEYS; row++)
			total += pounds[row][col];

		// get the average
		double average = total / NUM_MONKEYS;

		// display the daily average eaten for all monkeys
		cout << "Average amount of food eaten by all monkeys on day " << (col + 1)
			<< " is " << average << " pounds." << endl;
	}
}

// Function definition - find greatest and least amounts of food
void greatestLeast() {

	double least = pounds[0][0];		// holds least amount of food eaten by one monkey
	double greatest = pounds[0][0];		// holds greatest amount of food eaten by one monkey

	// calculate least and greatest amounts of food eaten by summing rows
	for (int row = 0; row < NUM_MONKEYS; row++)
	{
		for (int col = 0; col < NUM_DAYS; col++)
		{
			// determine what row is greatest
			if (pounds[row][col] > greatest)
				greatest = pounds[row][col];

			//  determine what row is least
			if (pounds[row][col] < least)
				least = pounds[row][col];
		}
	}

	// display the greatest and least amount of food eaten during the week by any one monkey
		cout << "Greatest amount of food eaten by any one monkey during the week is " << greatest << " pounds." << endl;
		cout << "Least amount of food eaten by any one monkey during the week is " << least << " pounds." << endl;
}
