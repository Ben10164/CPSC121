#include <iostream>
#include <string>

using namespace std;
/*
Problem Statement: Write a program that computes your grade point average after completion of 3 courses.
Inputs:
Grade point and number of credits for course 1
Grade point and number of credits for course 2
Grade point and number of credits for course 3
Outputs
Grade point average (GPA)
Relevant formula:
GPA=  (((gp1 ∗ num_creds1) + (gp2 ∗ num_creds2) + (gpt3 ∗ num_creds3) ))/(total_num_credits)
*/

/* Prompts the user for a grade point earned for a course */
double getGradePoint() {
	double temp = 0;
	cout << "Please enter the grade point for one of your classes: ";
	cin >> temp;
	return temp;
}

/* Prompts the user for the number of credits for a course */
int getCredits() {
	int temp;
	cout << "Enter the amount of credits for the previous class: ";
	cin >> temp;
	return temp;
}

/* Computes the weighted sum of credits for 3 courses */
double computeWeightedCredits(double grade_point1, double grade_point2, double grade_point3, int num_credits1, int num_credits2, int num_credits3) {
	double temp;
	temp = (grade_point1 * num_credits1) + (grade_point2 * num_credits2) + (grade_point3 * num_credits3);
	return temp;
}

/* Computes the total credits for 3 courses */
double computeTotalCredits(double grade_point1, double grade_point2, double grade_point3, int num_credits1, int num_credits2, int num_credits3) {
	double temp;
	temp = static_cast<double>(num_credits1) + static_cast<double>(num_credits2) + static_cast<double>(num_credits3);
	return temp;
}

/* Computes the GPA from weighted credits sum and total number of credits */
double computeGPA(double weighted_credits, int total_num_credits) {
	double gpa;
	gpa = weighted_credits / total_num_credits;
	return gpa;
}

/* Outputs the calculated gpa to the screen */
void displayGPA(double gpa) {
	cout << "Your GPA is: " << gpa << endl;
}

int main() {
	double grade_point1,grade_point2,grade_point3,weighted_credits,total_num_credits,gpa;
	int c1, num_credits2, num_credits3;
	grade_point1 = getGradePoint();
	c1 = getCredits();
	grade_point2 = getGradePoint();
	num_credits2 = getCredits();
	grade_point3 = getGradePoint();
	num_credits3 = getCredits();
	weighted_credits = computeWeightedCredits(grade_point1, grade_point2, grade_point3, c1, num_credits2, num_credits3);
	total_num_credits = computeTotalCredits(grade_point1, grade_point2, grade_point3, c1, num_credits2, num_credits3);
	gpa = computeGPA(weighted_credits, total_num_credits);
	displayGPA(gpa);
}