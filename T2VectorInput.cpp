/*
	This program is desinged to input the odd integers from 22-389
	into a vector, and output them onto the console.
	
	Created by: Logan Crockett
	On: 11/3/17
	Math1900
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {

	vector<int> OddNumbers;

	for (unsigned int loopCount = 22; loopCount <= 389; loopCount++) {
		if (loopCount % 2 != 0)
			OddNumbers.push_back(loopCount);
	}

	for (unsigned int loopCount = 0; loopCount <= OddNumbers.size() - 1; loopCount++) {
		cout << OddNumbers.at(loopCount) << " ";
	}
	system("pause");
	return 0;
}