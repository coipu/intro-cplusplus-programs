// Chapter 6, Programming Challenge 20: Stock Profit
#include <iostream>
using namespace std;

// function prototype
double profitOrLoss(double, double, double, double, double);

int main()
{
	// to hold the five amounts for each stock
	double numberShares, purchasePrice, purchaseComm, salePrice, saleComm;

	// get amounts from user
	cout << "Enter the number of shares: ";
	cin >> numberShares;
	cout << "Enter the purchase price per share: ";
	cin >> purchasePrice;
	cout << "Enter the purchase commission paid: ";
	cin >> purchaseComm;
	cout << "Enter the sale price per share: ";
	cin >> salePrice;
	cout << "Enter the sale commission paid: ";
	cin >> saleComm;

	// call function that returns if profit or loss and assign returned value to total
	double total = profitOrLoss(numberShares, purchasePrice, purchaseComm, salePrice, saleComm);

	// display loss or profit amount to screen
	if (total < 0)
		cout << "\nLoss amount: $" << total << endl;
	else if (total > 0)
		cout << "\nProfit amount: $" << total << endl;
}

// function definition
double profitOrLoss(double numberShares, double purchasePrice, double purchaseComm, double salePrice, double saleComm)
{
	// return the calculated amount
	return ((numberShares * salePrice) - saleComm) - ((numberShares * purchasePrice) + purchaseComm);
}
