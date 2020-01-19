/*
	This program is desinged to input nubers from an input file into an array,
	ask the user for a PIN number, and check it againest the array.
	
	Created by: Logan Crockett
	On: 10/27/17
	Math1900
*/

#include <iostream>
#include <fstream>

using namespace std;

int main() {

	int PinNumbers[20];//Array to hold all of the pin numbers from the input file
	int PinNumber = 0;

	ifstream inData;
	ofstream outData;

	inData.open("Input.txt");
	outData.open("Output.txt");

	if (!inData) {
		cout << "Could not open input file." << endl;
		system("pause");
		return 1;
	}

	if (!outData) {
		cout << "Could not open output file." << endl;
		system("pause");
		return 1;
	}

	for (int loopCount = 0; loopCount < 20; loopCount++) {
		//Puts the pin numbers into the array
		inData >> PinNumbers[loopCount];
	}

	for (int loopCount = 0; loopCount < 20; loopCount++) {
		//Outputs the number from the array
		outData << PinNumbers[loopCount] << endl;
	}

	cout << "Enter your pin number: ";
	cin >> PinNumber;
	cout << endl;
	//Searches for the pin number from the array
	for (int loopCount = 0; loopCount < 20; loopCount++) {
		//Checks to see if it is in the array
		if (PinNumber == PinNumbers[loopCount]) {
			cout << "Pin number found." << endl;
			loopCount++; //Incremented to accurately display the location in the file
			cout << "It was located in the " << loopCount << " location." << endl;
			system("pause");
			return 0;
		}
	}

	cout << "Pin number not found." << endl;
	cout << "See the bank manager." << endl;

	inData.close();
	outData.close();

	system("pause");

	return 1;
}