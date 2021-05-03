#include <iostream>
#include <ctime>

using namespace std;
/*
1. Write code that prompts the user for an integer (n). Display n random numbers representing
throws of a 6-sided die (e.g. integers in the range [1, 6] inclusive).
a. Draw a flowchart to model your solution to this problem
b. Solve this using a while loop
c. Solve this using a for loop
*/
int main()
{
	srand(time(NULL));
	int num = 0;
	cout << "How many dice do you want to throw: ";
	cin >> num;
	cout << "Using a for loop" << endl;
	for (int j = 1; j <= num; j++) {
		int i = rand() % 6 + 1;
		cout << "Dice " << j << " was " << i << endl;
	}
	cout << "Using a while loop" << endl;
	int temp = 1;
	while (temp <= num) {
		int i = rand() % 6 + 1;
		cout << "Dice " <<  temp << " was " << i << endl;
		temp++;
	}
	return 0;
}