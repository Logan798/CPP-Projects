/*
	This program is designed to behave like a bank ATM. It uses a class for the data types
	and functions.
	
	Created by: Logan Crockett
	On: 11/28/17
	Math1900
	
	Final Exam
*/

#include <iostream>
#include <iomanip> //for floating-point output
#include <fstream>
#include <cctype> //for toupper()
#include <string>
#include <cstdlib> //For exit()

using namespace std;

class ATM {
private:
	float Balance; //Balance of the account
	const int PINNumber = 5689;
	const float MinimumBalance = 300.0;
	string FirstName, LastName;
public:
	ATM(float InBalance, string FName, string LName) {
		Balance = InBalance;
		FirstName = FName;
		LastName = LName;
	}; //Constructor function prototype
	void PinCheck(); //Function prototype; designed to check the inputted and correct PIN
	float Withdraw(float); //Function protype; designed to perform a withdrawal and output to text file
	float Deposit(float); //Function Prototype; designed to perform a desposit and output to text file
};

int main() {

	float CurrentBalance = 0.0; //Balance to be inputted from user the first time
	string Name1, Name2; //First and last name, respectively
	char Quit = 'Q'; //Character used to quit do-while loop

	char BankCustomer; //Used to determine if they are a bank customer
	const float ServiceCharge = 20.0; //Service charge amount if they aren't a customer
	char TransactionType; //Inputted from user. Type of transaction to be performed

	ofstream Outdata;

	Outdata.open("Output.txt");

	cout << "Enter your first and last name separated by a space: ";
	cin >> Name1 >> Name2;

	cout << "Enter the current balance: " << endl;
	cin >> CurrentBalance;

	cout << "Are you a bank customer? Y/N : ";
	cin >> BankCustomer;

	BankCustomer = toupper(BankCustomer); //Capatilizes the letter

	if (BankCustomer == 'N') {
		cout << "There will a $" << ServiceCharge << " service charge. Do you wish to continue? Y/N : ";
		cin >> Quit;

		Quit = toupper(Quit); //Capatilizes the letter

		if (Quit == 'N') //If they say no, then the process will end
			return 1;
		else
			CurrentBalance = CurrentBalance - ServiceCharge;
	}


	ATM Account1(CurrentBalance, Name1, Name2); //Initializes the data in the class

	Account1.PinCheck();

	Outdata << "   Transaction     Amount     Balance" << endl; //Sets up the output file

	cout << fixed << showpoint << setprecision(2); //Floating-point output

	do {
		float Amount = 0.0; //Amount to be inputted

		system("cls"); //Clears the screen to make it easier to read

		cout << endl << "Select a transaction type: " << endl;
		cout << "D: Deposit" << endl;
		cout << "W: Withdrawal" << endl;
		cin >> TransactionType;

		TransactionType = toupper(TransactionType); //Capitlizes the letter
		
		switch (TransactionType) {
		case 'D' : //Deposit
			cout << "Enter amount: ";
			cin >> Amount;
			CurrentBalance = Account1.Deposit(Amount);
			Outdata << "    " << TransactionType << "              $" << Amount
				<< "       $" << CurrentBalance << endl;; //Outputs to the file
			break;
		case 'W' : //Withdraw
			cout << "Enter amount: ";
			cin >> Amount;

			if (Amount > CurrentBalance) { //If it would overdraft
				cout << "Cannot complete transaction. Insufficient funds.";
				Outdata << "    " << TransactionType << "              $" << Amount
				<< "      Insufficeint Funds." << endl;
				break;
			}
				
			CurrentBalance = Account1.Withdraw(Amount);
			Outdata << "    " << TransactionType << "              $" << Amount
				<< "       $" << CurrentBalance << endl;; //Outputs to the file
			break;
		default:
			cout << "Input not recognized. Please try again." << endl;
			break;
		}

		cout << endl << "Another transaction? If not, type the letter 'q'" << endl;
		cin >> Quit;

		Quit = toupper(Quit);

	} while (Quit != 'Q');

	Outdata.close();

	system("pause");
	return 0;
}

void ATM::PinCheck() {
	int CurrentPin; //PIN to be inputted by user
	int Count = 0;

	while (Count < 2) {
		cout << "Enter your PIN Number: ";
		cin >> CurrentPin;

		if (CurrentPin == PINNumber)
			return;
		else
			Count++;
	}
	//If they input it incorrectly after two attempts
	cout << "You have exhausted all attempts." << endl;

	system("pause");
	exit(1);
}

float ATM::Deposit(float amount) {
	const float MinServiceCharge = 7.0; //Charge if they go below the minimum amount
	Balance = Balance + amount;

	if (Balance < MinimumBalance) {
		Balance = Balance - MinServiceCharge;
		cout << "Deposit: $" << amount << endl;
		cout << "Minimum Balnce charge: $" << MinServiceCharge << endl;
		cout << "New balance: $" << Balance << endl;
	}
	else {
		cout << "Deposit: $" << amount << endl;
		cout << "New balance: $" << Balance << endl;
	}

	return Balance;
}

float ATM::Withdraw(float amount) {
	const float MinServiceCharge = 7.0; //Charge if they go below the minimum amount
	Balance = Balance - amount;

	if (Balance < MinimumBalance) {
		Balance = Balance - MinServiceCharge;
		cout << "Withdraw Amount: $" << amount << endl;
		cout << "Minimum Balnce charge: $" << MinServiceCharge << endl;
		cout << "New balance: $" << Balance << endl;
	}
	else {
		cout << "Withdraw Amount: $" << amount << endl;
		cout << "New balance: $" << Balance << endl;
	}

	return Balance;
}