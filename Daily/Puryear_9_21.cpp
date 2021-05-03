#include <iostream>

using namespace std;

int main()
{

   // SW development method

   /*
			Problem #2 Mileage Reimbursement
			Write a program that calculates mileage reimbursement for a salesperson at the rate of $.35 per
			mile.
			Example output:
			MILEAGE REIMBURSEMENT CALCULATOR
			Please enter the beginning odometer reading: 13505.2
			Please enter the ending odometer reading: 13810.6
			You traveled 305.4 miles. At $0.35 per mile, your reimbursement is $106.89
			*/

   // 1. problem requirements
   // I want the program to accept the two reading of the odometer, before and after, and then output the calculated reimbursement depending on the two odometer readings

   // 2. analyze the problem
   // inputs: start odometer, end odometer
   // outputs: distance traveled, reinbursement
   // relationships: distance traveled = start odometer - end odometer, reinbursement = distance traveled * 0.35

   // 3. design the algorithm (pseudocode)
   // create doubles endOmeter, startOmeter, distanceTraveled, reimbursement
   // write line, "What was the starting odometer reading?"
   // set the users input as startOdometer
   // write line, "What is the ending odometer reading?"
   // set the users input as endOdometer,
   // set distanceTraveled to be startOdometer - endOdometer
   // set reimbursement to distanceTraveled * 0.35
   // output reimbursement as a sentence stating all the variables

   // 4. implement the algorithm (C++)

   double startOdometer;
   double endOdometer;
   double distanceTraveled;
   double reimbursement;

   cout << "Please enter the starting odometer reading: ";
   cin >> startOdometer;
   cout << "Pease enter the ending odometer reading: ";
   cin >> endOdometer;

   distanceTraveled = endOdometer - startOdometer;
   reimbursement = distanceTraveled * 0.35;

   cout << "You traveled " << distanceTraveled << " miles. At $0.35 per mile, your reimbursement is $" << reimbursement << endl;

   // 5. test the completed program
   // test with values from sheet

   // 6. maintain the program

   return 0;
}
