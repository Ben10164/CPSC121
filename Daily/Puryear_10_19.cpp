#include <iostream>
#include <cmath> // for pow()

using namespace std;

double getUserWeight();
double getUserHeight();
double computeBMI(double userHeight, double userWeight);
void displayBMI(double userHeight, double userWeight, double BMI);

int main() {
	double weight = getUserWeight();
	double height = getUserHeight();
	double bmi = computeBMI(height, weight);
	displayBMI(height, weight, bmi);
	if (bmi < 18.5) {
		cout << "Underweight" << endl;
	}
	else if (bmi <= 25) // only way to get here is if BMI >= 18.5
	{
		cout << "Normal" << endl;
	}
	else { // BMI >= 18.5 && BMI > 25 so really BMI > 25
		cout << "Overweight" << endl;
	}
	return 0;
}

//Prototypes
double getUserWeight() {
	double userWeight = 0;
	cout << "What is your Weight in pounds: ";
	cin >> userWeight;
	return userWeight;
}
double getUserHeight() {
	double userHeight = 0;
	cout << "What is your Height in inches: ";
	cin >> userHeight;
	return userHeight;
}
double computeBMI(double userHeight, double userWeight) {
	double bmi = 0;
	bmi = (userWeight / pow(userHeight, 2)) * 703;
	return bmi;
}
void displayBMI(double userHeight, double userWeight, double BMI) {
	cout << "With a height of " << userHeight << " inches and a weight of " << userWeight << " pounds. Your BMI is " << BMI << endl;
}