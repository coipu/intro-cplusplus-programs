// Chapter 6, Programming Challenge 5: Falling Distance
#include <iostream>
using namespace std;

// function prototype
double fallingDistance(int seconds);

int main()
{
	int seconds = 0;  // time in seconds
	double distance = 0; // distance in meters

	for (int count = 1; count <= 10; count++)
	{
		// call function with seconds 1-10 as arguments
		distance = fallingDistance(count);
		cout << "The object fell " << distance << " meters in "
			<< count << " seconds." << endl;
	}

	return 0;
}

// function definition
double fallingDistance(int seconds)
{
	double distance;
	const double GRAVITY = 9.8;
	// calculate distance in meters
	distance = .5 * GRAVITY * seconds * seconds;
	return distance;
}
