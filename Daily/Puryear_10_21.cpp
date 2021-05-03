#include <iostream>
#include <cmath> // for pow()

using namespace std;
/*
Output the snowboard in centimeter
|
V
calculate snowboard length
|
V
get users height
*/
int getUserHeight();
int calculateSnowboardLength(int inches);
double convertInchesToCentimeters(int inches);
void displaySnowBoardHeight(int inches, int snowboardCM);

int main() {
	int height = getUserHeight();
	int snowboardInches = calculateSnowboardLength(height);
	double snowboardCM = convertInchesToCentimeters(snowboardInches);
	displaySnowBoardHeight(height, snowboardCM);
	return 0;
}

int getUserHeight() {
	int height = 0;
	cout << "Please enter your height: ";
	cin >> height;
	return height;
}
int calculateSnowboardLength(int inches) {
	int snowboard = inches * 0.88;
	return snowboard;
}
double convertInchesToCentimeters(int inches) {
	double cm = inches * 2.54;
	return cm;
}
void displaySnowBoardHeight(int inches, int snowboardCM) {
	cout << "With a height of " << inches << " inches, your snowboard should be " << snowboardCM << " centimeters!" << endl;
}