// Chapter 4, Programming Challenge 17: Personal Best
#include <iostream>
#include <string>
using namespace std;

int main() {

	double height1, height2, height3; // hold vault heights
	string vaulter, date1, date2, date3; // hold name of vaulter and dates of vaults

	cout << "Enter the name of the pole vaulter: "; // get name of pole vaulter
	cin >> vaulter;

	cout << "\nEnter the three vault heights in meters, separated by a space: "; // get three heights
	cin >> height1 >> height2 >> height3;

	// input validation for heights and get three dates
	if (height1 < 2.0 || height2 < 2.0 || height3 < 2.0)
		cout << "\nPlease only use values between 2.0 and 5.0";
	else if (height1 > 5.0 || height2 > 5.0 || height3 > 5.0)
		cout << "\nPlease only use values between 2.0 and 5.0";
	else	{
		cout << "\nEnter the dates of the three vaults in the format mm/dd/yy, separated by a space: ";
		cin >> date1 >> date2 >> date3;
	}

	// display best height
	cout << "\nBest vault heights for " << vaulter << ":" << endl;
	if (height1 > height2 && height1 > height3)
		cout << height1 << " meters on " << date1 << endl;
	else if (height2 > height1 && height2 > height3)
		cout << height2 << " meters on " << date2 << endl;
	else
		cout << height3 << " meters on " << date3 << endl;

	// display 2nd best height
	if ((height1 < height2 && height1 > height3) || (height1 > height2 && height1 < height3))
		cout << height1 << " meters on " << date1 << endl;
	else if ((height2 < height1 && height2 > height3) || (height2 > height1 && height2 < height3))
		cout << height2 << " meters on " << date2 << endl;
	else
		cout << height3 << " meters on " << date3 << endl;

	// display 3rd best height
	if (height1 < height2 && height1 < height3)
		cout << height1 << " meters on " << date1 << endl;
	else if (height2 < height1 && height2 < height3)
		cout << height2 << " meters on " << date2 << endl;
	else
		cout << height3 << " meters on " << date3 << endl;

	return 0;
}
