// Chapter 7, Programming Challenge 16: World Series Champions
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	const int WINNERS = 108;			// Array size for World Series winners
	string allWinners[WINNERS];			// Array for winners of World Series
	int count = 0;						// loop counter variable
	string allTeams;					// string for names of teams to be displayed
	string teamName;					// string for chosen team input by user
	int wins = 0;						// to add up number of wins

	// file stream object to read data from a file and open the file
	ifstream teamsFile("C:\\Users\\jenni\\Desktop\\Teams.txt");

	// display list of all MLB teams
	cout << "The Major League Baseball teams are: " << endl;
	while (getline(teamsFile, allTeams))
		cout << allTeams << endl;

	teamsFile.close();					// close the teams file

	// ask user to enter name of one of the teams
	cout << "\nEnter the name of a team: ";
	getline(cin, teamName);

	// file stream object to read data from a file and open file
	ifstream winnersFile("C:\\Users\\jenni\\Desktop\\WorldSeriesWinners.txt");

	// create array of all winners in World Series file
		while (count < WINNERS)
	{
		getline(winnersFile, allWinners[count]);
		count++;
	}

	// compare chosen team and teams in winner files, add up number of occurences
	for (int count = 0; count < WINNERS; count++)  // go through each winner
	{
		if (teamName == allWinners[count]) // if teamname matches winner, add 1 to wins
			wins++;
	}

		winnersFile.close();			// close the winners file

	// display number of times that team has won World Series
	cout << "\nThe " << teamName << " have won the World Series " << wins << " time(s). \n";

	return 0;
}
