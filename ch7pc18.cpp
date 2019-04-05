// Chapter 7, Programming Challenge 18: Tic-Tac-Toe Game
#include <iostream>
#include <iomanip>
using namespace std;

// player variable
char player = 'X';

// initalize 3x3 board with asterisks
char board[3][3] = { '*','*','*','*','*','*','*','*','*' };

// function prototypes
void displayBoard();
void getLocation();
char findWinner();

int main()
{
	// display board of asterisks only
	cout << "Lets's play Tic-Tac-Toe!\n\n";
	displayBoard();

	// loop to play nine times (draw if no one wins after ninth time)
	for (int count = 0; count < 9; count++)
	{
		// get user input
		getLocation();

		// display board after player has placed mark
		displayBoard();

		// check to see if someone won, and break out of for loop if so
		if (findWinner() == 'X')
		{
			cout << "\nPlayer X wins!" << endl;
			break;
		}
		else if (findWinner() == 'O')
		{
			cout << "\nPlayer O wins!" << endl;
			break;
		}

		// switch to other player for next iteration
		if (player == 'X')
			player = 'O';
		else
			player = 'X';
	}

	// after ninth iteration, if no one wins, it's a tie game
	if (findWinner() != 'X' && findWinner() != 'O')
		cout << "\nTie game!" << endl;

	return 0;
}

//******************************************************************
// Function definition: display board on screen

void displayBoard()
{
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			cout << setw(4) << board[x][y] << " ";
		}
		cout << endl;
	}
}

// Function definition: to get user input on where to put mark

void getLocation()
{
	// player enters row and column numbers for placement of mark
	int row, col;
	cout << "\n" << "Player " << player << ", enter row and column numbers (0, 1, or 2) separated by a space: ";
	cin >> row >> col;
	cout << endl;

	// assign mark to chosen space
	if (row == 0 && col == 0)
		board[0][0] = player;
	else if (row == 0 && col == 1)
		board[0][1] = player;
	else if (row == 0 && col == 2)
		board[0][2] = player;
	else if (row == 1 && col == 0)
		board[1][0] = player;
	else if (row == 1 && col == 1)
		board[1][1] = player;
	else if (row == 1 && col == 2)
		board[1][2] = player;
	else if (row == 2 && col == 0)
		board[2][0] = player;
	else if (row == 2 && col == 1)
		board[2][1] = player;
	else if (row == 2 && col == 2)
		board[2][2] = player;

}

// Function definition: to see if there is a winner

char findWinner()
{
	// player X wins: across
	if (board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X')
		return 'X';
	if (board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X')
		return 'X';
	if (board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X')
		return 'X';
	// down
	if (board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X')
		return 'X';
	if (board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X')
		return 'X';
	if (board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X')
		return 'X';
	// diagonal
	if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X')
		return 'X';
	if (board[2][0] == 'X' && board[1][1] == 'X' && board[0][2] == 'X')
		return 'X';

	// player O wins: across
	if (board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O')
		return 'O';
	if (board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O')
		return 'O';
	if (board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O')
		return 'O';
	// down
	if (board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O')
		return 'O';
	if (board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O')
		return 'O';
	if (board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O')
		return 'O';
	// diagonal
	if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O')
		return 'O';
	if (board[2][0] == 'O' && board[1][1] == 'O' && board[0][2] == 'O')
		return 'O';
}
