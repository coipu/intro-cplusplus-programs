// Chapter 7, Programming Challenge 10: Driver's License Exam
#include <iostream>
using namespace std;

// function prototypes
int checkAnswers();
void listIncorrect();

// declare variables and constants
const int NUM_QUESTIONS = 20;
const int PASSING_SCORE = 15;
char correctAnswers[] = {'A', 'D', 'B', 'B', 'C', 'B', 'A', 'B', 'C', 'D', 'A', 'C', 'D', 'B', 'D', 'C', 'C', 'A', 'D', 'B' };
char studentAnswers[NUM_QUESTIONS];	// to hold student answers to questions
int wrongAnswers[NUM_QUESTIONS];	// to hold total number of incorrect student answers

int main()
{
	int correctCounter = 0;

	// ask user to enter student's answers for all questions, store in studentAnswers array
	for (int count = 0; count < NUM_QUESTIONS; count++)
	{
		cout << "Enter the answer to question " << (count + 1) << ": ";
		cin >> studentAnswers[count];

		// input validation - only accept A, B, C, and D as answers
		while (studentAnswers[count] != 'A' && studentAnswers[count] != 'B' && studentAnswers[count] != 'C' && studentAnswers[count] != 'D')
		{
			cout << "Please only enter the capital letters A, B, C, or D. Please re-enter the answer: ";
			cin >> studentAnswers[count];
		}
	}

	// compare correct answers with student answers
	correctCounter = checkAnswers();
	if (correctCounter < NUM_QUESTIONS)
			listIncorrect();		// call function if there are incorrect answers

	// display message whether student has passed or failed the exam and how many were answered correctly and incorrectly
	cout << "You have " << (correctCounter >= PASSING_SCORE ? "passed" : "failed") << " the exam." << endl;
	cout << "Total number of correctly answered questions: " << correctCounter << endl;
	cout << "Total number of incorrectly answered questions: " << (NUM_QUESTIONS - correctCounter) << endl;

	// if any questions were answered wrong, display list of those question numbers
	if (correctCounter < NUM_QUESTIONS)
	{
		cout << "Question numbers of the incorrectly answered questions: ";
		for (int count = 0; count < (NUM_QUESTIONS - correctCounter); count++)
			cout << wrongAnswers[count] + 1;

	}

	return 0;
}

// *********************************************************
// function definition: to compare answers between two arrays
int checkAnswers()
{
	int counter = 0;
	for (int count = 0; count < NUM_QUESTIONS; count++)  // go through each question
	{
		if (studentAnswers[count] == correctAnswers[count]) // if student answer is correct, then add 1 to counter
			counter++;
	}
	return counter;
}

// function definition: to create list of numbers of questions answered incorrectly
void listIncorrect()
{
	int counter = 0;
	for (int count = 0; count < NUM_QUESTIONS; count++)  	// go through each question
	{
		if (correctAnswers[count] != studentAnswers[count])  // if answers do not match
		{
			wrongAnswers[counter] = count; // keep track of number for each question answered incorrectly, put into new array
			counter++;
		}
	}
} 
