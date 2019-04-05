// Chapter 9, Programming Challenge 2: Test Scores 1
#include <iostream>
#include <iomanip>
using namespace std;

// function prototypes
void selectionSort(double *, int);
double calcAverage(double *, int);

int main()
{
	// variables
	double *testScores = nullptr;	// pointer to array of test scores
	double averageScore;			// holds average score for all tests
	int numScores;			// holds total number of scores to input

	// get number of scores from user
	cout << "Enter total number of scores: ";
	cin >> numScores;

	// dynamically allocate an array large enough to hold a user-defined number of scores
	testScores = new double[numScores];

	// get test scores
	for (int i = 0; i < numScores; i++)
	{
		do
		{
			cout << "Enter score #" << (i + 1) << ": ";
			cin >> *(testScores + i);

			// input validation
			if (*(testScores + i) < 0)
			{
				cout << "Scores must be greater than 0. Please re-enter: " << endl;
			}

		} while (*(testScores + i) < 0);
	}

	// call selection sort function
	selectionSort(testScores, numScores);

	// call function to calculate the average of all test scores
	averageScore = calcAverage(testScores, numScores);

	// display data
	cout << "\nTest scores in ascending order:\n";
	for (int i = 0; i < numScores; i++)
	{
		cout << "#" << (i + 1) << ": " << *(testScores + i) << endl;
	}
	cout << fixed << showpoint << setprecision(2);
	cout << "Average score: " << averageScore << endl;

	// free the memory and set pointer to 0
	delete[] testScores;
	testScores = nullptr;

	return 0;
}

//***********************************************************
// Function to perform selection sort on array of test scores.

void selectionSort(double *testScores, int numScores)
{
	int startscan, minIndex;
	double minValue;

	for (startscan = 0; startscan < (numScores - 1); startscan++)
	{
		minIndex = startscan;
		minValue = *(testScores + startscan);
		for (int i = startscan + 1; i < numScores; i++)
		{
			if (*(testScores + i) < minValue)
			{
				minValue = *(testScores + i);
				minIndex = i;
			}
		}
		*(testScores + minIndex) = *(testScores + startscan);
		*(testScores + startscan) = minValue;
	}
}

//**************************************************************
// Function to calculate average of all test scores

double calcAverage(double *testScores, int numScores)
{
	double total = 0;

	for (int i = 0; i < numScores; i++)
	{
		total += *(testScores + i);
	}

	return total / numScores;
}
