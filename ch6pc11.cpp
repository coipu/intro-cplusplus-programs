// Chapter 6, Programming Challenge 11: Lowest Score Drop
#include <iostream>
using namespace std;

// function prototype
void getScore(int &testScore);
void calcAverage(int score1, int score2, int score3, int score4, int score5);
int findLowest(int score1, int score2, int score3, int score4, int score5);

int main()
{
	// to hold five scores
	int score1, score2, score3, score4, score5;

	// call getScore once for each of five scores
	getScore(score1);
	getScore(score2);
	getScore(score3);
	getScore(score4);
	getScore(score5);

	// call calcAverage once, with five scores passed to it
	calcAverage(score1, score2, score3, score4, score5);

	return 0;
}

// function definitions
void getScore(int &testScore)
{
	// ask user for test score, store in reference parameter variable
	cout << "Enter test score: ";
	cin >> testScore;
	// input validation - no score less than 0 or higher than 100
	if (testScore < 0 || testScore > 100)
	{
		cout << "Scores must be between 0 and 100. Please re-enter score: ";
		cin >> testScore;
	}

}

void calcAverage(int score1, int score2, int score3, int score4, int score5)
{
	// call findLowest to find lowest score
	int lowestScore = findLowest(score1, score2, score3, score4, score5);
	// calculate and display average of four highest scores
	double average = (score1 + score2 + score3 + score4 + score5 - lowestScore) / 4.0;
	cout << "The average score is " << average << endl;
}

int findLowest(int score1, int score2, int score3, int score4, int score5)
{
	// find and return lowest of five scores
	int lowest = score1;
	if (score2 < lowest)
		lowest = score2;
	if (score3 < lowest)
		lowest = score3;
	if (score4 < lowest)
		lowest = score4;
	if (score5 < lowest)
		lowest = score5;
	return lowest;
}
