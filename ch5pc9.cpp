// Chapter 5, Programming Challenge 9: Hotel Occupancy
#include <iostream>
#include <iomanip>
using namespace std;

int main() {

	double floors = 0; // to hold number of floors
	double rooms = 0; // to hold number of rooms per floor
	double occupied = 0; // to hold number of occupied rooms per floor
	double totalRooms = 0;  // accumulator initialized with zero
	double totalOccupied = 0; // accumulator initialized with zero
	double percentOccupied = 0; // calculation of total occupied divided by total rooms

	// get number of floors
		cout << "Enter the number of floors in the hotel: ";
		cin >> floors;
		while (floors < 1)  // input validation for number of floors
		{	cout << "Number of floors must be at least 1. Please re-enter number: ";
			cin >> floors;		}

	// loop to ask for number of rooms on each floor and how many are occupied
	for (int count = 1; count <= floors; count++)
	{
		if (count == 13) // to skip floor 13
			continue;

		cout << "Enter the number of rooms on floor " << count <<": ";
		cin >> rooms;
		while (rooms < 10)  // input validation for number of rooms
		{	cout << "Number of rooms per floor must be at least 10. Please re-enter number: ";
			cin >> rooms;		}

		cout << "Enter the number of rooms on this floor that are occupied: ";
		cin >> occupied;

		totalRooms += rooms;  // accumulate running total of rooms
		totalOccupied += occupied; // accumulate running total of occupied rooms
	}

		// calculate percentage of occupied rooms
		percentOccupied = (totalOccupied / totalRooms) * 100;

		// display number of rooms, number occupied, number unoccupied, and percentage occupied
		cout << "\nTotal hotel rooms: " << totalRooms << endl;
		cout << "Total occupied rooms: " << totalOccupied << endl;
		cout << "Total unoccupied rooms: " << totalRooms - totalOccupied << endl;
		cout << "Percentage of rooms occupied: " << fixed<< setprecision(2) << percentOccupied << "%" << endl;

	return 0;
}
