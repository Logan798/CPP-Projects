/*
	This program is designed to use a class to do checkbook functions, suh as a withdrawal.
	Created by: Logan Crockett
	On: 11/17/17
	Math1900
*/

#include <iostream>
using namespace std;

class CheckBook {

private:
	float balance;

public:
	CheckBook() { //Constructor
		balance = 0;
	}
	void Open(float); //Open with initial deposit
	void Withdraw(float);
	float CheckBalance();
};

int main() {

	CheckBook Account1; //Object
	Account1.Open(25); //Puts 25 dollars into the balance
	Account1.Withdraw(10); //Takes 10 out of the balance

	cout << "Account1 balance is " << Account1.CheckBalance() << endl;

	system("pause");
	return 0;
}

void CheckBook::Open(float InitialDeposit) {
	balance = InitialDeposit;
}

void CheckBook::Withdraw(float WithdrawAmount) {
	balance = balance - WithdrawAmount;
}

float CheckBook::CheckBalance() {
	return balance;
}