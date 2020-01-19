/*
This program is designed to input loan information and
calculate the payments for various term lengths.
Created by: Logan Crockett
CISP Midterm Exam
*/

#include <iostream>
#include <cctype>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
	float price;//Price of car
	float downPayment;//Intial payment on car
	float tradeIn;//Price of car that was traded in	
	float loanAmt;//The Loan Amount after calculation
	float annualIntRate, annualIntPercent;//The interest rate as a fraction and a percent, in that order of declaration.
	float monIntRate;//Interest rate per month
	float monPayment;//The monthly payment to be made
	int noMonths;//Number of months
	char Quit;//The character to terminate the loop and program will be 'q'
	cout << fixed << setprecision(2);//Sets up output to show the decimal to two places

	do {//Greet user and propmt for input
		cout << "Thank you for choosing Davy Crockett's Run-down motors." << endl;
		cout << " Please enter the price of the vehicle, the Trade-in value, the Down Payment, and the Annual Interest Rate." << endl;
		cout << "Please enter a price between $50.00 and $45000.00: $";
		cin >> price;
		while (price < 50.00 || price > 45000.00) {//Is the price at least 50.00 and not more than 45,000.00?
			cout << endl << "Please enter a price between $50.00 and $45000.00." << endl << "Price: ";//Re-propmt user for input?
			cin >> price;
		}
		cout << endl << "Please enter a Trade-in value less than the price and greater than or equal to zero: $";
		cin >> tradeIn;
		while (tradeIn < 0 || tradeIn > price) {//Does the trade-in equal at least 0 and is it greater than the price?
			cout << endl << "Please enter a Trade-in value less than the price and greater than or equal to zero. "
				<< endl << "Trade-in: $";//Re=propmt user for input
			cin >> tradeIn;
		}
		cout << endl << "Please enter a Down Payment less than " << (price - tradeIn) << ": $";
		cin >> downPayment;
		while (downPayment < 0 || downPayment >= (price - tradeIn)) {//Is the down payment at least 0 or less than the price minus the loan ammount?
			cout << endl << "Please enter a Down Payment less than " << (price - tradeIn)
				<< "and greater than or equal to 0." << endl << "Down Payment: $";//Re-propmt user for input
			cin >> downPayment;
		}
		cout << endl << "Please enter the Annual Interest Rate as a decimal between 0.00 and 0.18: ";
		cin >> annualIntRate;
		while (annualIntRate <= 0 || annualIntRate > 0.18) {//Is it between 0% and 18%?
			cout << endl << "Please enter the Annual Interest Rate as a decimal between 0.00 and 0.18: "
				<< endl << "Annual Interest Rate: ";//Re-propmt user for input
			cin >> annualIntRate;
		}
		cout << endl << "-----------------------" << endl;
		
		monIntRate = annualIntRate / 12.0;//Divides the annual interest rate into 12 months
		annualIntPercent = annualIntRate * 100.0;//Converts the Interest rate into a percent
		loanAmt = price - downPayment - tradeIn;//Gets the amount to be leased

		//Output Loan information and payments
		cout << "Davy Crockett's Run-down Motors" << endl << endl;//Name of dealership
		cout << "Vehichle Price: $" << price << endl//Display the price of the Vehicle
			<< "Trade-in Value: $" << tradeIn << endl;//Display the trade-in value
		cout << "Down Payment:   $" << downPayment << endl//Display the down payment ammount
			<< "---------------------" << endl;//Line used for addition of the above three ammounts
		cout << "Loan Amount: $" << loanAmt << endl//Display the loan ammount
			<< "Annual Interest Rate: " << annualIntPercent << "%" << endl//Display the Annual Interst Rate
			<< "Monthly Payment Options" << endl
			<< "---------------------- " << endl;//Informative prompt

		//This will calculate the amounts for 5 different loan terms and display them
		for (int loopCount = 0; loopCount < 5; loopCount++) {
			switch (loopCount) {
			case 0: noMonths = 12;
				cout << "12 Months: ";  break;//Caculates for 12 months
			case 1: noMonths = 24;
				cout << "24 Months: ";  break;//Calculates for 24 months
			case 2: noMonths = 36;
				cout << "36 Months: ";  break;//Calculates for 36 months
			case 3: noMonths = 48;
				cout << "48 Months: ";  break;//Calculates for 48 months
			case 4: noMonths = 60;
				cout << "60 Months: ";  break;//Calculates for 60 months
			}
			//Calculates the monthly payment; noMonths has to equal 12, 24, 36, 48, 60
			monPayment = (loanAmt * monIntRate) / (1.0 - pow((1 + monIntRate), -noMonths));
			cout <<"$" << monPayment << endl;
		}
		//Prompts user if he/she wants to recalculate another loan
		cout << "Would you like to recalculate a loan with different numbers? If so, enter 'y' " <<
			"to restart. " << endl << " If not, then enter 'q' to terminate the program." << endl;
		cin.get();
		cin.get(Quit);//Get a letter to determine if the loop will quit.

	} while (Quit != 'q');//Character to terminate loop
	cout << "Thanks for choosing Davy Crockett's Run-down Motors!" << endl;
	cin.get();
	cin.get();
	return 0;
}