// Chapter 4, Programming Challenge 24: Long-Distance Calls
#include <iostream>
#include <iomanip>
using namespace std;

int main() {

	// variables for time call starts, minutes the call lasted, and calculation of charges
	double startTime, callMinutes, charges;

	// get starting time
	cout << "Enter start time of call in the format hh.mm: ";
	cin >> startTime;

	// input validation for times
	if (startTime > 23.59 || (startTime - static_cast<int>(startTime)) > 59)
		cout << "Please enter a time before 23.59 and make sure minutes do not exceed 59." << endl;
	else
	{
		// get duration of call in minutes
		cout << "Enter number of minutes of the call: ";
		cin >> callMinutes;

		// calculate charges based on minutes and time of day
		if (startTime >= 0 && startTime <= 6.59)
			charges = callMinutes * .05;

		else if (startTime >= 7 && startTime <= 19)
			charges = callMinutes * .45;

		else if (startTime >= 19.01 && startTime <= 23.59)
			charges = callMinutes * .2;

		cout << "Charges for this call amount to $" << setprecision(2) << fixed << charges << endl;
	}

	return 0;
}
