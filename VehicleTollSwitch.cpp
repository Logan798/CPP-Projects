/*
	This program is designed to ask the user for a number corresponding to a 
	vehicle type, and then output the toll fee.
	
	Created by: Logan Crockett
	On: 10/4/17
	Math1900
*/

#include <iostream>

using namespace std;

int main() {

	int vehicle_type;
	cout << "Enter 1 for passenger car" << endl;
	cout << "Enter 2 for bus" << endl;
	cout << "Enter 3 for truck" << endl;
	cout << "Enter 4 trailer" << endl;
	cin >> vehicle_type;

	switch (vehicle_type) {

	case 1:
		cout << "Pay $" << 3.00 << endl;
		break;
	case 2:
		cout << "Pay $" << 3.50 << endl;
		break;
	case 3:
		cout << "Pay $" << 5.25 << endl;
		break;
	case 4:
		cout << "Pay $" << 7.80 << endl;
		break;
	default:
		cout << "Talk to the attendant" << endl;
		break;
	}

	system("pause");

	return 0;
}