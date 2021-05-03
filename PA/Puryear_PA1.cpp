#include <cmath>
#include <iomanip>
#include <iostream>
#include <math.h>
#include <string>

using namespace std;

int main()
{
   //Initializing all of the variables
   string userName;
   string userFrom;
   string favCar;

   int years;

   double userAge;
   double ageDiv;
   double carCost;
   double yearlyRate;
   double monthlyRate;
   double monthlyCost;
   double totalCost;

   //This is the age of the ai
   double aiAge = 4.0;

   //Question_1

   cout << "What is your name?" << endl;
   //Input
   getline(cin, userName);
   //Response
   cout << "Hi there, it is nice to meet you " << userName << endl;

   //Question_2

   cout << "Where are you from ? " << endl;
   //Input
   getline(cin, userFrom);
   //Response
   cout << "Thats cool! I've always wanted to go to " << userFrom << endl;

   //Question_3

   cout << "So this might be a bit weird having me ask you this, but I might as well ask.\nHow old are you? "
        << "I'm 4 if it makes you feel better"
        << endl;
   //Input
   cin >> userAge;
   //Divides the user age by the ai age
   ageDiv = userAge / aiAge;
   //Response
   cout << "That's awesome! That actually make you " << ageDiv << " times older than me!" << endl;

   //Question_5

   //Starts off by getting the cars name
   cout << "So whats your favorite car?" << endl;
   cin.get();
   getline(cin, favCar);
   cout << "Thats awesome! I feel like a "
        << " would be really fun to drive around town!" << endl;

   //Now it gets the price of said car
   cout << "How much does that car cost again?" << endl;
   carCost;
   cin >> carCost;
   //Response, then asks for the amount of years the user will spend paying for it
   cout << "Wow that is expensive, geez. How many years do you want to spend paying for it?" << endl;
   cin >> years;
   //Now asks for the anual interest rate
   cout << "So whats the interest rate anually?" << endl;
   cin >> yearlyRate;

   //Calculates the monthly rate
   monthlyRate = yearlyRate / 100 / 12;
   //Calculates the monthly cost with the equation (r(p)/(1-((1+r)^-n))
   //monthlyRate * carCost is r(p)
   //1.0 + monthlyRate is (1+r)
   //0 - (years * 12.0) is -n
   monthlyCost = (monthlyRate * carCost) / (1 - (pow((1.0 + monthlyRate), (0 - (years * 12.0)))));

   //Calculates the total cost by multiplying the monthly cost by the total amount of months
   totalCost = monthlyCost * (years * 12.0);
   //Outputs answer
   cout << "So every month you need to pay " << fixed << monthlyCost << ".\nThat also means your total price will be "
        << totalCost << ". Does that sound good?" << endl;

   //Goodbye!
   cout << "Well I have to go! Thanks for talking with me " << userName << "! It was really fun!" << endl;
   return 0;
}