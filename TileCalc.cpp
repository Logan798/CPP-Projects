/*
This program is designed to input the number of rooms and size of tiles
and calculate the number of tiles it would take to fil the rooms.

Made by:Logan Crockett
Chapter 8: Problem 6
*/

#include <iostream>
using namespace std;

//Gets the total ammount of tiles needed
int TotalTiles(int rooms) {
	int totalTiles;//Total number of tiles
	int tileSize; //Size of tiles in inches
	int loopCount = 0;//Initialize the loopcount for the calculations
	int widthInFeet; //Width in feet
	int lengthInFeet;//Length in feet
	int feet, inches;//Feet and inches for rooms
	int sum = 0;//Sum of number of tiles needed
	int roomTiles;//Number of tiles a room needs
	int numOfBoxes;//Number of boxes needed
	int extraTiles;//Number of extra tiles

	cout << "Enter size of tile in inches: ";
	cin >> tileSize; //Input the size of the tiles

	while (loopCount < rooms) {
		cout << "Enter room width (feet and inches, separated by a space): ";
		cin >> feet >> inches;//Input feet and inches
		cout << endl;
		while (feet < 0 || inches < 0) {
			cout << "Enter a positive number for feet and inches: ";//Re-prompt user for input
			cin >> feet >> inches;
			cout << endl;
		}
		while (inches > 11) {
			cout << "The inches were either one foot or greater. Please re-enter the feet and inches: ";//Re-prompt user for input
			cin >> feet >> inches;
			cout << endl;
		}
		widthInFeet = feet + (inches / 12);//Gets the width in feet
		if ((widthInFeet % tileSize) > 0)
			widthInFeet = widthInFeet + 1;

		cout << "Enter room length (feet and inches, separated by a space): ";
		cin >> feet >> inches;//Input feet and inches
		cout << endl;
		while (feet < 0 || inches < 0) {
			cout << "Enter a positive number for feet and inches: ";//Re-prompt user for input
			cin >> feet >> inches;
			cout << endl;
		}
		while (inches > 11) {
			cout << "The inches were either one foot or greater. Please re-enter the feet and inches: ";//Re-prompt user for input
			cin >> feet >> inches;
			cout << endl;
		}
		lengthInFeet = feet + (inches / 12);//Gets the length in feet
		if ((lengthInFeet % tileSize) > 0)
			lengthInFeet = lengthInFeet + 1;

		//Gets the number of tiles needed for a room
		roomTiles = widthInFeet * lengthInFeet;
		cout << "Room requires " << roomTiles << " tiles." << endl;

		//Gets total amount of tiles needed for a job
		sum = sum + roomTiles;
		totalTiles = sum;

		loopCount++;
	}

	//This ensures the right calculation of boxes
	numOfBoxes = totalTiles / 20;
	if ((numOfBoxes % 20) > 0)
		numOfBoxes = numOfBoxes + 1;

	//Gets the number of extra tiles
	extraTiles = (numOfBoxes * 20) - totalTiles;

	cout << "Total tiles required is " << totalTiles << endl;
	cout << "Number of boxes needed is " << numOfBoxes << endl;
	cout << "There will be " << extraTiles << " extra tiles." << endl;

	return totalTiles;
}

int main() {
	int rooms;//Number of rooms

	cout << "Enter number of rooms: ";
	cin >> rooms; //Input rooms
	cout << endl;
	while (rooms < 1) {
		cout << "Enter a the number of rooms greater than or equal to 1: ";//Re-prompt user for input
		cin >> rooms;//Input rooms
		cout << endl;
	}
	TotalTiles(rooms);//Gets and displays the number of tiles, boxes, and how many extra there will be.

	cin.get();
	cin.get();
	return 0;
}
