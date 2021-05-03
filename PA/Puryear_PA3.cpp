/*
Name: Ben Puryear
Class: CPSC 121
Date: October 9, 2020
Programming Assignment: PA3
Description: This program does 6 activities specified in the PA3 rubric, 5 regular activities and 1 extra credit
Sources: No sources
*/

//I Attempted the extra credit

#include <cmath>
#include <iostream>
#include <string>

using namespace std;

int main()
{
   //Task 1 Var
   int userInputNum1;
   int temp1;
   int ans1;
   //Task 2 Var
   int payStubs2;
   double totalIncome2;
   double tempDouble2;
   //Task 3 Var
   int userInputNum3;
   int ans3;
   int digitNum3;
   int input3;
   int num3;
   int temp3;
   int numOfDigits3;
   //Task 4 Var
   double pi4;
   int userInputNum4;
   int sign4;
   ;
   int j4 = 1;
   //Task 5 Var
   int userInputNum5;
   //Extra
   int heightB;
   int tempE;
   int e;

   //Task 1
   cout << "(Task 1) Enter an positive integer number. The output will be the factorial of said number: ";
   cin >> userInputNum1;

   temp1 = userInputNum1;
   ans1 = temp1;
   //Start the while loop
   if (userInputNum1 > 1)
   {
      //Calculates the factorial by multipling it by itself minus one, minus one
      while (temp1 > 1)
      {
         ans1 *= temp1 - 1;
         temp1--;
      }
   }
   else
   {
      //In case it is 1 or 0, the factorial is 1.
      ans1 = 1;
   }
   cout << "The factorial (n!) of " << userInputNum1 << " is " << ans1 << ". This was found using a while loop." << endl;
   ans1 = userInputNum1;
   if (userInputNum1 > 1)
   {
      //Same as the while loop, calculates the factorial by multiplying the number by itself minus one on repeat
      for (int i = userInputNum1; i > 1; i--)
      {
         ans1 *= i - 1;
      }
   }
   else
   {
      //Also the same, in case it is 1 or 0, it is 1
      ans1 = 1;
   }
   cout << "The factorial (n!) of " << userInputNum1 << " is " << ans1 << ". This was found using a for loop." << endl
        << endl;
   system("pause");
   cout << endl;

   // ------------------------------ //

   //Task 2
   totalIncome2 = 0;
   tempDouble2 = 0;

   cout << "(Task 2) Please enter the number of paystubs (integer): ";
   cin >> payStubs2;
   //this for loop asks the user for their paycheck amount for the given amount of paychecks they had
   for (int i = 0; i < payStubs2; i++)
   {
      cout << "Please enter the amount (integer) for stub #" << (i + 1) << ": ";
      cin >> tempDouble2;
      totalIncome2 += tempDouble2;
   }
   cout << "Total salary for the year: $" << totalIncome2 << " Tax bracket: ";
   //depending on their total income, they will either be in the low, medium, or high income
   if (totalIncome2 < 15000)
   {
      cout << "low income" << endl;
   }
   else if (totalIncome2 <= 200000)
   {
      cout << "medium income" << endl;
   }
   else
   {
      cout << "high income" << endl;
   }
   cout << endl;
   system("pause");
   cout << endl;

   // ------------------------------ //

   //Task 3
   ans3 = 0;
   cout << "(Task 3) Enter an integer to sum the digits of: ";
   cin >> userInputNum3;
   input3 = userInputNum3;
   num3 = userInputNum3;
   temp3 = 0;
   numOfDigits3 = 0;
   //Finds the number of digits
   while (num3 / 10 != 0)
   {
      numOfDigits3 += 1;
      num3 /= 10;
   }

   //This for loop calculates the sum of the numbers digits by taking the modulo one by one and adding them up
   for (int i = 0; i <= numOfDigits3; i++)
   {
      digitNum3 = fabs(userInputNum3 % 10);
      userInputNum3 = userInputNum3 / 10;
      ans3 += digitNum3;
   }
   cout << "The sum of " << input3 << " is " << ans3 << endl
        << endl;
   system("pause");
   cout << endl;

   // ------------------------------ //

   //Task 4
   pi4 = 0;
   sign4 = 1;
   j4 = 1;

   cout << "(Task 4) Enter the number of terms to approximate pi (integer): ";
   cin >> userInputNum4;

   //Sign is a variable that is either 1 or -1, and depending on its value, the for loop with either add or subtract the next number
   if (userInputNum4 > 0)
   {
      for (int i = 1; i <= userInputNum4; i++)
      {
         //This is where the variable sign is used
         if (sign4 > 0)
         {
            pi4 += 4.0 / j4;
         }
         else
         {
            pi4 -= 4.0 / j4;
         }
         j4 += 2;
         sign4 *= -1;
      }
   }
   else
   {
      cout << "That number isnt above 0" << endl;
   }
   cout << "After " << userInputNum4 << " terms, pi was approximated as " << pi4 << endl;
   cout << endl;
   system("pause");
   cout << endl;

   // ------------------------------ //

   //Task 5
   cout << "(Task 5) Please enter an integer for a pattern: ";
   cin >> userInputNum5;
   cout << "Part 1:" << endl;
   for (int i = 1; i <= userInputNum5; i++)
   {
      for (int j = 1; j <= i; j++)
      {
         cout << i;
      }
      cout << endl;
   }
   cout << "Part 2:" << endl;
   for (int i = 1; i <= userInputNum5; i++)
   {
      for (int j = 1; j <= i; j++)
      {
         cout << i;
      }
      //After the numbers are generated this outputs the square of the number, finishing the pattern
      cout << " " << pow(i, 2) << endl;
   }
   cout << endl;
   system("pause");
   cout << endl;

   //------------------------------ //

   //Task Bonus
   heightB = 0;
   cout << "(Bonus) Please enter an integer height: ";
   cin >> heightB;
   tempE = heightB - 1;

   for (int k = heightB; k > 0; k--)
   {
      for (int j = tempE; j > 0; j--)
      {
         for (int i = 6; i > 0; i--)
         {
            cout << ' ';
         }
      }
      cout << " o *******";
      for (int l = heightB - 1; l >= tempE + 1; l--)
      {
         for (int m = 6; m > 0; m--)
         {
            cout << ' ';
         }
      }
      cout << "*" << endl;
      for (int j = tempE; j > 0; j--)
      {
         for (int i = 6; i > 0; i--)
         {
            cout << ' ';
         }
      }
      cout << "/|\\*";
      for (int l = heightB; l >= tempE + 1; l--)
      {
         for (int m = 6; m > 0; m--)
         {
            cout << ' ';
         }
      }
      cout << "*" << endl;
      for (int j = tempE; j > 0; j--)
      {
         for (int i = 6; i > 0; i--)
         {
            cout << ' ';
         }
      }
      cout << "/ \\*";
      for (int l = heightB; l >= tempE + 1; l--)
      {
         for (int m = 6; m > 0; m--)
         {
            cout << ' ';
         }
      }
      cout << "*" << endl;
      tempE--;
   }
   cout << "****";
   e = heightB * 6;
   while (e >= 0)
   {
      cout << '*';
      e--;
   }
   return 0;
}