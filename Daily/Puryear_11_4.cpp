#include <iostream>
#include <ios>
#include <fstream>
#include <string>
#include <cmath>
#include <array>
#include <iomanip>

using namespace std;

const int SIZE = 10;

void fillArray(int[], int);
void printArray(const int[], int);
void addValueArray(int[], int);

int main() {
	int numbers[SIZE];
	int i = 0;

	ifstream inputFile;
	inputFile.open("food.txt");
	if (inputFile.is_open()) {
		cout << "Successfully opened input file" << endl;
	}
	else {
		cout << "Failed to open input file" << endl;
		exit(-1);
	}

	string food[SIZE];

	int temp = 0;

	string trash;

	int count = 0;
	while (!inputFile.eof()) {
		getline(inputFile, food[temp]);\
		count++;
		temp++;
	}
	for (int j = 0; j < count; j++) {
		cout << food[j] << " ";
	}
	cout << endl;


	srand(time(0));

	fillArray(numbers, SIZE);

	printArray(numbers, SIZE);

	addValueArray(numbers, SIZE);
	printArray(numbers, SIZE);

	return 0;
}



void addValueArray(int numbers[], int size) {
	int i, value = 0;
	cout << "Enter a value: ";
	cin >> value;

	for (i = 0; i < size; i++) {
		numbers[i] += value;
	}
}

void printArray(const int numbers[], int size) {
	int i;

	for (i = 0; i < size; i++) {
		cout << numbers[i] << endl;
	}
}

void fillArray(int numbers[], int size) {
	int i;
	for (i = 0; i < size; i++) {
		numbers[i] = rand() % 6 + 1;
	}
}
