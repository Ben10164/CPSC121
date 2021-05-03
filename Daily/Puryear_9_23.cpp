#include <iostream>
#include <string>

using namespace std;

int main()
{
   // SW development method
   // 1. problem requirements
   // The program should be able to predict the score needed on a final exam to achieve a desired overall grade in a course

   // 2. analyze the problem
   // inputs: Desired Grade, Minimum average required, current average, weight of the final
   // outputs: required grade on the final to get the desired grade
   // relationships: the output percent should be required to get the desired grade

   // 3. design the algorithm (pseudocode)
   /*
		output what the desired grade is, minimum average required, current average, weight. then get the inputs.
		create double req
		make req equal to the goal percentage - current percentage * (100% - weightage) / weightage

		output the req
	*/

   // 4. implement the algorithm (C++)

   string reqGrade;
   double reqPercent;
   double currentPercent;
   double weight;
   double req;

   cout << "Please enter the desired grade as a letter: ";
   cin >> reqGrade;

   cout << "Please enter the desired grade (Ex: B- = 80): ";
   cin >> reqPercent;

   cout << "Please enter your current grade: ";
   cin >> currentPercent;

   cout << "Please enter the weight of your final: ";
   cin >> weight;

   req = (reqPercent - currentPercent * (1 - (weight / 100))) / (weight / 100);

   cout << "You will need a " << req << "% to get a " << reqGrade << " on the final" << endl;

   // 5. test the completed program
   // test with values from sheet

   // 6. maintain the program

   return 0;
}

/*
Problem #4 Grade Calculator
Write a program that predicts the score needed on a final exam to achieve a desired grade in a
course. The program should interact with the user as follows:
Enter desired grade=> B
Enter minimum average required=> 79.5
Enter current average in course=> 74.6
Enter how much the final counts
as a percentage of the course grade=> 25
You need a score of 94.20 on the final to get a B.
*/