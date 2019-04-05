// Chapter 4, Programming Challenge 14: Bank Charges
#include <iostream>
#include <iomanip>
using namespace std;

int main() {

	const double MONTHLY_FEE = 10.00; // holds monthly account fee
	const double LOW_FEE = 15.00; // holds low balance fee
	int checks; // holds number of checks written
	double beginBalance, totalChecks, totalFees; // hold balance and calculations

	cout << "Enter the beginning balance: ";  // get opening balance
	cin >> beginBalance;

	if (beginBalance < 0)
		cout << "Your account is overdrawn!" << endl;  // display message if account is below 0

	cout << "Enter the number of checks written: "; // get number of checks
	cin >> checks;

	// determine rate by number of checks and validate for negative numbers
	if (checks > 0 && checks < 20)
		totalChecks = checks * .1;
	else if (checks >= 20 && checks <= 39)
		totalChecks = checks * .08;
	else if (checks >= 40 && checks <= 59)
		totalChecks = checks * .06;
	else if (checks >= 60)
		totalChecks = checks * .04;
	else
		cout << "Please enter a positive value for the number of checks written." << endl;

	// calculate fees depending on beginning balance
	if (beginBalance < 400 && checks > 0) 	{
		totalFees = totalChecks + MONTHLY_FEE + LOW_FEE;
		cout << "Monthly service fees amount to $" << setprecision(2) << fixed << totalFees
			<< ", which includes $10 for the monthly fee, $15 for the low balance fee, and $"
			<< totalChecks << " for checks written." << endl;
	}
	else if (beginBalance > 400 && checks > 0)	{
		totalFees = totalChecks + MONTHLY_FEE;
		cout << "Monthly service fees amount to $" << setprecision(2) << fixed << totalFees
			<< ", which includes $10 for the monthly fee and $" << totalChecks << " for checks written." << endl;
	}

	return 0;
}
