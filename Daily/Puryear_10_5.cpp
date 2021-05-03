#include <iostream>

using namespace std;

int main()
{
	//__ bottles of Mountain Dew Baja Blast on a wall. __ bottles of Mountain Dew Baja Blast. Take 1 down, pass it around, __ bottles of Mountain Dew Baja Blast on a wall.

	//Step 1:
	//The purpose is to recreate the classic song, "Bottles of bear on the wall", but with Baja Blast.

	//Step 2:
	//Inputs: none
	//Outputs: the song

	//Step 3:
	/*
	declare an int named amount, set it equal to 99:
	use one of the following tactics to...
		make an int i = 0, and be less than or equal to amount, i ++:
		make a for loop where amount is greater than 0, amount --:
		make a while loop where it is active while amount is > 0:
		make a while loop where int i is < amount, then every itteration make i ++:
		Use a do while loop:
	... output the song
	*/

	int amount = 99;
	int amountBackUp = amount;

	//1
	for (int i = 0; i < amount; i++) {
		int current = amount - i;
		cout << current << " bottles of Mountain Dew Baja Blast on a wall. " << current << " bottles of Mountain Dew Baja Blast. Take 1 down, pass it around, " << current - 1 << " bottles of Mountain Dew Baja Blast on a wall." << endl;
	}

	//2
	for (int i = amount; i > 0; i--) {
		int current = i;
		cout << current << " bottles of Mountain Dew Baja Blast on a wall. " << current << " bottles of Mountain Dew Baja Blast. Take 1 down, pass it around, " << current - 1 << " bottles of Mountain Dew Baja Blast on a wall." << endl;
	}

	//3
	while (amount > 0) {
		int current = amount;
		cout << current << " bottles of Mountain Dew Baja Blast on a wall. " << current << " bottles of Mountain Dew Baja Blast. Take 1 down, pass it around, " << current - 1 << " bottles of Mountain Dew Baja Blast on a wall." << endl;
		amount--;
	}

	//4
	while (amount < amountBackUp) {
		int current = amountBackUp - amount;
		cout << current << " bottles of Mountain Dew Baja Blast on a wall. " << current << " bottles of Mountain Dew Baja Blast. Take 1 down, pass it around, " << current - 1 << " bottles of Mountain Dew Baja Blast on a wall." << endl;
		amount++;
	}

	//5
	do {
		int current = amount;
		cout << current << " bottles of Mountain Dew Baja Blast on a wall. " << current << " bottles of Mountain Dew Baja Blast. Take 1 down, pass it around, " << current - 1 << " bottles of Mountain Dew Baja Blast on a wall." << endl;
		amount--;
	} while (amount > 0);

	//Step 5:
	//Done

	//Step 6:
	//Done
	return 0;
}