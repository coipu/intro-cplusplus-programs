// Chapter 12, Programming Challenge 13: Inventory Program
#include <iostream>
#include <iomanip>
#include <cctype>
#include <fstream>

using namespace std;

// array sizes
const int DESC_SIZE = 1000, DATE_SIZE = 11;

// structure declaration
struct Inventory
{
	char description[DESC_SIZE];
	int quantity;
	double wholesaleCost;
	double retailCost;
	char dateAdded[DATE_SIZE];
};

// function prototypes
void addRecord(Inventory &, fstream &);
void displayRecord(Inventory &, fstream &);
void changeRecord(Inventory &, fstream &);
long byteNum(int);
void displayError();
bool testDate(char [], int);

int main()
{
	Inventory record;	// holds info about record
	fstream file;	// file stream object
	int choice;		// holds user menu choice
  int recNum;   // holds record number

	// open file for binary input and output
	file.open("inventory.dat", ios::out | ios::in | ios::binary);

	// test for errors
	if (!file)
	{
		cout << "Error opening file. Program aborting.\n";
		return 0;
	}

	do
	{
		// display menu
		cout << "\nInventory Program Menu\n";
		cout << " 1. Add new records to the file\n";
		cout << " 2. Display any record in the file\n";
		cout << " 3. Change any record in the file\n";
		cout << "Enter a number from the menu or -1 to quit: ";
		cin >> choice;

    if (choice == 1)
       addRecord(record, file);

    else if (choice == 2)
       displayRecord(record, file);

    else if (choice == 3)
       changeRecord(record, file);

	} while (choice != -1);

	// close file
	file.close();

	return 0;
}

//******************************************************
// function to add new records to file
//******************************************************
void addRecord(Inventory &record, fstream &file)
{

  char again;		// holds Y or N for adding more

do
{
	// get description
		cout << "\nEnter information about the item: \n";
		cout << "Description: ";
    cin.ignore();   // skip over the remaining newline
		cin.getline(record.description, DESC_SIZE);

  // get quantity
  do
  {
    cout << "Quantity: ";
		cin >> record.quantity;
		if (record.quantity < 0)
			displayError();
  }	while (record.quantity < 0);

  // get wholesale cost
  do
  {
    cout << "Wholesale Cost: ";
		cin >> record.wholesaleCost;
		if (record.wholesaleCost < 0)
			displayError();
  } while (record.wholesaleCost < 0);

  // get retail cost
	do
  {
    cout << "Retail Cost: ";
		cin >> record.retailCost;
    cin.ignore();
		if (record.retailCost < 0)
      displayError();
  } while (record.retailCost < 0);

  // get date
  do
	{
		cout << "Date Added (format MM/DD/YYYY): ";
		cin.getline(record.dateAdded, DATE_SIZE);
    testDate(record.dateAdded, DATE_SIZE);
    if (!testDate(record.dateAdded, DATE_SIZE))
		   cout << "Error! Please enter again. ";
	} while (!testDate(record.dateAdded, DATE_SIZE));

 		// write the contents of the person structure to the file
		file.write(reinterpret_cast<char *>(&record), sizeof(record));

    // determine whether the user wants to write another record
		cout << "\nDo you want to enter another record? Y/N ";
		cin >> again;
		//cin.ignore(); // skip over the remaining newline

} while (again == 'Y' || again == 'y');
}

//******************************************************
// function to display any record in file
//******************************************************
void displayRecord(Inventory &record, fstream &file)
{
int recNum;

  cout << "\nWhich record do you want to display? ";
	cin >> recNum;
  recNum = recNum - 1;

	file.seekg(byteNum(recNum), ios::beg);
	file.read(reinterpret_cast<char *>(&record), sizeof(record));

	cout << "\nDescription: ";
	cout << record.description << endl;
	cout << "Quantity: ";
	cout << record.quantity << endl;
	cout << "Wholesale Cost: ";
	cout << record.wholesaleCost << endl;
	cout << "Retail Cost: ";
	cout << record.retailCost << endl;
	cout << "Date Added: ";
	cout << record.dateAdded << endl;
}

//******************************************************
// function to change any record in file
//******************************************************
void changeRecord(Inventory &record, fstream &file)
{
	int recNum;

	// Get the record number of the desired record.
	cout << "\nWhich record do you want to change? ";
	cin >> recNum;
  recNum = recNum - 1;

	// Move to the record and read it.
	file.seekg(recNum * sizeof(record), ios::beg);
	file.read(reinterpret_cast<char *>(&record), sizeof(record));

	// Display the record contents.
	cout << "\nDescription: ";
	cout << record.description << endl;
	cout << "Quantity: ";
	cout << record.quantity << endl;
	cout << "Wholesale Cost: ";
	cout << record.wholesaleCost << endl;
	cout << "Retail Cost: ";
	cout << record.retailCost << endl;
	cout << "Date Added: ";
	cout << record.dateAdded << endl;

	// enter new record data
		cout << "\nEnter new information about the item: \n";
		cout << "Description: ";
    cin.ignore();   // skip over the remaining newline
		cin.getline(record.description, DESC_SIZE);

  // get quantity
  do
  {
    cout << "Quantity: ";
		cin >> record.quantity;
		if (record.quantity < 0)
			displayError();
  }	while (record.quantity < 0);

  // get wholesale cost
  do
  {
    cout << "Wholesale Cost: ";
		cin >> record.wholesaleCost;
		if (record.wholesaleCost < 0)
			displayError();
  } while (record.wholesaleCost < 0);

  // get retail cost
	do
  {
    cout << "Retail Cost: ";
		cin >> record.retailCost;
    cin.ignore();
		if (record.retailCost < 0)
      displayError();
  } while (record.retailCost < 0);

  // get date
  do
	{
		cout << "Date Added (format MM/DD/YYYY): ";
		cin.getline(record.dateAdded, DATE_SIZE);
    testDate(record.dateAdded, DATE_SIZE);
    if (!testDate(record.dateAdded, DATE_SIZE))
		   cout << "Error! Please enter again. ";
	} while (!testDate(record.dateAdded, DATE_SIZE));

	// Move back to the beginning of this record's position.
	file.seekp(recNum * sizeof(record), ios::beg);

	// Write the new record over the current record.
	file.write(reinterpret_cast<char *>(&record), sizeof(record));
	}

//******************************************************
// function to return byte number in file of record
// whose number is passed as the argument
long byteNum(int recNum)
{
	return sizeof(Inventory) * recNum;
}

//******************************************************
// function for input validation (numbers must be > 0)
void displayError()
{
	cout << "Number must be greater than 0. Please enter again: \n";
}

//******************************************************
// function to test validation of date input by user
// (from Program 10-2 in book)

bool testDate(char dateAdded[], int size)
{
  int count;

  // test first two characters for numeric digits
  for (count = 0; count < 2; count++)
  {
    if (!isdigit(dateAdded[count]))
      return false;
  }

  // test characters 4 and 5 for numeric digits
  for (count = 3; count < 5; count++)
  {
    if (!isdigit(dateAdded[count]))
      return false;
  }

  // test last four characters for numeric digits
  for (count = 6; count < size - 1; count++)
  {
    if (!isdigit(dateAdded[count]))
      return false;
  }
  return true;
}
