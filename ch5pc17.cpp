// Chapter 5, Programming Challenge 17: Sales Bar Chart
#include <iostream>
#include <string>
using namespace std;

int main() {

	double store1, store2, store3, store4, store5; // to hold sales amounts for each store

	// get sales amount for each store
	cout << "Enter today's sales for store 1: ";
	cin >> store1;
	cout << "Enter today's sales for store 2: ";
	cin >> store2;
	cout << "Enter today's sales for store 3: ";
	cin >> store3;
	cout << "Enter today's sales for store 4: ";
	cin >> store4;
	cout << "Enter today's sales for store 5: ";
	cin >> store5;

	// calculate number of stars for each store
	store1 /= 100;
	store2 /= 100;
	store3 /= 100;
	store4 /= 100;
	store5 /= 100;

	// display bar chart
	cout << "\nSALES BAR CHART:" << endl;
	cout << "(Each * = $100)" << endl;

	// for loops to generate correct number of stars
	cout << "Store 1: ";
	for (int count = 1; count <= store1; count++)
	{
		cout << "*";
	}
		cout << endl;

	cout << "Store 2: ";
	for (int count = 1; count <= store2; count++)
	{
		cout << "*";
	}
		cout << endl;

	cout << "Store 3: ";
	for (int count = 1; count <= store3; count++)
	{
		cout << "*";
	}
		cout << endl;

	cout << "Store 4: ";
	for (int count = 1; count <= store4; count++)
	{
		cout << "*";
	}
		cout << endl;

	cout << "Store 5: ";
	for (int count = 1; count <= store5; count++)
	{
		cout << "*";
	}
		cout << endl;


	return 0;
}
