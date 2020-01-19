/*
	This program is desinged to act like an ATM Machine
	by asking the user what they would like to do with their
	bank account, such as view their balance, or make a deposist
	or withdrawal.
	
	Created by: Logan Crockett
	On: 10/5/17
	Math1900
*/

#include <iostream>
#include <iomanip> //For setprecision()

using namespace std;

int main() {

	char customer;
	int bank_type;
	double balance = 2500.67; //Previous account balance
	double withdrawal, deposit;
	float ServiceCharge = 3.50; //Charge if they are not a customer with the bank

	cout << "Are you a bank customer? Enter Y for Yes, and N for No" << endl;
	cin >> customer;
	cout << "Enter 1 for account balance" << endl;
	cout << "Enter 2 for withdrawal" << endl;
	cout << "Enter 3 for deposit" << endl;
	cin >> bank_type;

	cout << fixed << showpoint << setprecision(2); //For floating-point output

	switch (bank_type) {

	case 1: //Account balance
		if (customer == 'N') {
			cout << "Service charge: $" << ServiceCharge << endl;
			balance = balance - ServiceCharge;
			cout << "Your current balance is $" << balance << endl;
		}
		else
			cout << "Your current balance is $" << balance << endl;
		break;
	case 2: //Withdrawal
		cout << "How much would you like to withdraw? " << endl;
		cin >> withdrawal;

		if (withdrawal > balance) {
			cout << "The withdrawal amount is $" << withdrawal << endl;
			cout << "The withdrawal amount is greater than the account balance." << endl;
			cout << "Cannot complete transaction. Program will terminate." << endl;
			system("pause");
			return 0;
		}
		else {
			if (customer == 'N') {
				balance = balance - withdrawal - ServiceCharge;
				cout << "Withdrawal amount: $" << withdrawal << endl;
				cout << "Service charge: $" << ServiceCharge << endl;
				cout << "New account balance: $" << balance << endl;
			}
			else {
				balance = balance - withdrawal;
				cout << "Withdrawal amount: $" << withdrawal << endl;
				cout << "New account balance: $" << balance << endl;
			}
		}
		break;
	case 3: //Deposit
		cout << "Enter deposit amount: " << endl;
		cin >> deposit;

		if (customer == 'N') { //If they are not a customer of the bank
			balance = (balance + deposit) - ServiceCharge;
			cout << "Deposit amount: $" << deposit << endl;
			cout << "Service charge: $" << ServiceCharge << endl;
			cout << "New account balance: $" << balance << endl;
		}
		else {
			balance = balance + deposit;
			cout << "Deposit amount: $" << deposit << endl;
			cout << "New account balance: $" << balance << endl;
		}
		break;
	default:
		cout << "Input not recognized. Program will terminate." << endl;
		system("pause");
		return 1;
		break;
	}

	system("pause");

	return 0;
}