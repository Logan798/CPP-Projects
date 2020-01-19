/*
	This program is designed to ask the user for the
	numbers of hours they have worked, and their payrate.
	Then, it will calculate and output the amount the get paid.
	
	Created By: Logan Crockett
	On: 9/25/17
	Math1900

	Values:
	Payrate: $15.75
	Hours1: 52.2  Amount: 918.23
	Hours2: 18 Amount: 283.50
	Hours3: 40.0 Amount: 630

	*/

#include <iostream>
#include <iomanip> //for setprecision()

using namespace std;

int main() {

	float numHours = 0; //Number of hours worked
	float payRate = 0; //Payrate
	float totalPaid = 0; //Amount to be paid

	cout << "Enter the number of hours worked: " << endl;
	cin >> numHours;
	cout << "Enter the payrate: " << endl;
	cin >> payRate;

	if (numHours <= 40.0)
		totalPaid = payRate * numHours; //Normal Pay
	else
		totalPaid = ((payRate  * 1.5) * (numHours - 40.0)) + (payRate * 40.0); //Overtime pay

	cout << fixed << showpoint << setprecision(2);
	cout << "The amoount at $" << payRate << " for " << numHours << " hours is $"
		<< totalPaid << endl;

	system("pause");

	return 0;
}