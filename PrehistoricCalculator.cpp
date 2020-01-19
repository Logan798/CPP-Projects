/*
This program is designed to input a range of prehistoric dates
and output the time periods those years are in.

Made by: Logan Crockett
CISP Chapter 10, problem 3
Created on: 11/18/16
*/

#include <iostream>
#include <cctype> //For toupper()
using namespace std;

enum Years {
	PRECAMBRIAN, CAMBRIAN, ORDOVICIAN, SILURIAN, DEVONIAN,CARBONIFEROUS,
	PERMIAN, TRIASSIC, JURASSIC,CRETACEOUS, PALEOGENE, NEOGENE};

/*
This function takes the inputed years and sets
the loop counters equal to a period in the enumeration.
Then, it displays the periods.
*/
void YearFinder(int startYear, int endYear, int loopcount, int LoopCount) {
	//Takes the inputed start year and determines what period it is in.
	if (startYear >= 4500)
		loopcount = PRECAMBRIAN;//Zero
	else if (startYear < 4500 && startYear >= 570)
		loopcount = CAMBRIAN;//One
	else if (startYear < 570 && startYear >= 500)
		loopcount = ORDOVICIAN;//Two
	else if (startYear < 500 && startYear >= 435)
		loopcount = SILURIAN;//Three
	else if (startYear < 435 && startYear >= 395)
		loopcount = DEVONIAN;//Four
	else if (startYear < 395 && startYear >= 345)
		loopcount = CARBONIFEROUS;//Five
	else if (startYear < 345 && startYear >= 280)
		loopcount = PERMIAN;//Six
	else if (startYear < 280 && startYear >= 225)
		loopcount = TRIASSIC;//Seven
	else if (startYear < 225 && startYear >= 192)
		loopcount = JURASSIC;//Eight
	else if (startYear < 192 && startYear >= 136)
		loopcount = CRETACEOUS;//Nine
	else if (startYear < 136 && startYear >= 65)
		loopcount = PALEOGENE;//Ten
	else if (startYear < 65 && startYear >= 0)
		loopcount = NEOGENE;//Eleven

	//Takes the inputed end year and determines what period it is in
	if (endYear >= 4500)
		LoopCount = PRECAMBRIAN;//Zero
	else if (endYear < 4500 && endYear >= 570)
		LoopCount = CAMBRIAN;//One
	else if (endYear < 570 && endYear >= 500)
		LoopCount = ORDOVICIAN;//Two
	else if (endYear < 500 && endYear >= 435)
		LoopCount = SILURIAN;//Three
	else if (endYear < 435 && endYear >= 395)
		LoopCount = DEVONIAN;//Four
	else if (endYear < 395 && endYear >= 345)
		LoopCount = CARBONIFEROUS;//Five
	else if (endYear < 345 && startYear >= 280)
		LoopCount = PERMIAN;//Six
	else if (endYear < 280 && endYear >= 225)
		LoopCount = TRIASSIC;//Seven
	else if (endYear < 225 && endYear >= 192)
		LoopCount = JURASSIC;//Eight
	else if (endYear < 192 && endYear >= 136)
		LoopCount = CRETACEOUS;//Nine
	else if (endYear < 136 && endYear >= 65)
		LoopCount = PALEOGENE;//Ten
	else if (endYear < 65 && endYear >= 23)
		LoopCount = NEOGENE;//Eleven

	//Switches loopCount to display the time periods involved
	for (loopcount, LoopCount; LoopCount <= loopcount; loopcount--) {
		switch (loopcount) {
		case 0: cout << "Precambrian" << endl; break;
		case 1: cout << "Cambrian" << endl; break;
		case 2: cout << "Ordovician" << endl; break;
		case 3: cout << "Silurian" << endl; break;
		case 4: cout << "Devonian" << endl; break;
		case 5: cout << "Carboniferous" << endl; break;
		case 6: cout << "Permian" << endl; break;
		case 7: cout << "Triassic" << endl; break;
		case 8: cout << "Jurassic" << endl; break;
		case 9: cout << "Cretaceous" << endl; break;
		case 10: cout << "Paleogene" << endl; break;
		case 11: cout << "Neogene" << endl; break;
		}
	}
	return;
}

int main() {
	int StartYear;//Beginning year of time period; Should be bigger than end year
	int EndYear;//End year of the time period; Should be smaller than start year
	int StartCount =0;//Counter for the starting year
	int EndCount = 0;//Counter for the ending year
	char Quit;//'Q'; Will be used to exit the loop and terminate the program

	do {
		//Inputs the years and checks to make sure they are B.C.
		cout << "Enter the start of the time period ( in millions of years): ";
		cin >> StartYear;
		while (StartYear <= 0) { //Checks to make sure the year is in B.C.
			cout << endl << "Please re-enter the year in B.C.: ";
			cin >> StartYear;
		} 
		cout << endl << "Enter the end of the time period (in millions of years): ";
		cin >> EndYear;
		while (EndYear <= 0) {//Checks to make sure the year is in B.C.
			cout << endl << "Please re-enter the year in B.C.: ";
			cin >> EndYear;
		}

		cout << endl << "Time periods included in " << StartYear << " B.C. to "
			<< EndYear << " B.C. :" << endl;

		YearFinder(StartYear, EndYear, StartCount, EndCount);//Sets up the counter to display the time period.

		cout << "Re-enter a range of years? Type any character to continue or 'Q' to quit." << endl;
		cin >> Quit;
		toupper(Quit);

	} while (Quit != 'Q');
	cin.get();
	return 0;
}