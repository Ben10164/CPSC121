/*
Name: Ben Puryear
Class: CPSC 121
Due Date: 10/14/2020
Assignment: PA4
Use: This program completes all the requirements for PA4
Note: No further notes
*/
#include <cmath>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

int main()
{
   srand(time(NULL));

   bool gameActive = true;

   cout << "Welcome to Craps, to start off this game, you must roll 2 dice." << endl;
   cout << "If the sum is 7 or 11 on the first throw, you win" << endl;
   cout << "if the sum is 2 3 or 12 on the first throw, house wins (this is called craps)" << endl;
   cout << "if the sum is 4 5 6 8 9 10, this number becomes your \"point\", and you continue rolling till you reroll that number" << endl;
   cout << "BUT, while rerolling for your point, if you roll a 7, you lose" << endl;
   string userInput = "";
   while (userInput != "Continue")
   {
      cout << "Please enter 'Continue' to continue: ";
      cin >> userInput;
   }
   int money = 100;

   while (gameActive)
   {
      cout << endl;
      /*
		Original Bet Process
		*/
      int bet = 0;
      if (money == 0)
      {
         cout << "Im sorry but you are out of money" << endl;
         gameActive = false;
      }
      else
      {
         while (true)
         {
            cout << "Current money: " << money << endl;
            cout << "What is your opening bet? (Ante is 1): ";
            cin.ignore(256, '\n');
            cin >> bet;
            if (cin.fail())
            {
               cout << "Please enter an integer" << endl;
               cin.clear();
            }
            else if (bet <= 0)
            {
               cout << "Ante must be above 0" << endl;
            }
            else if (bet > money)
            {
               cout << "Im sorry, but your bet for " << bet << " is more than your current money, " << money << " Please enter a lower bet amount." << endl;
            }
            else
            {
               break;
            }
         }
         cout << "So your current bet is " << bet << endl;

         /*
			First Dice Roll
			*/
         //Dice 1
         int di1 = 0;
         di1 = rand() % 6 + 1;
         //Dice 2
         int di2 = 0;
         di2 = rand() % 6 + 1;

         int diTotal = di1 + di2;

         cout << "Di 1 was " << di1 << " and Di 2 was " << di2 << " so your total is " << diTotal << endl;
         //If they rolled a 7 or 11 they win
         if (diTotal == 7 || diTotal == 11)
         {
            cout << "You win! You rolled a " << diTotal << " on the first turn!" << endl
                 << endl;
            //Adjusts money accordingly
            money += bet;
         }
         //If they rolled a Craps!
         else if (diTotal == 2 || diTotal == 3 || diTotal == 12)
         {
            cout << "Craps! You rolled a " << diTotal << " meaning you lost! House wins :(" << endl
                 << endl;
            //Adjusts money accordingly
            money -= bet;
         }
         else
         {
            cout << "Your point is " << diTotal << " now the real game begins >:)" << endl
                 << endl;
            int point = diTotal;
            diTotal = 0;
            while (diTotal != point)
            {
               /*
					Bet Making Process
					*/
               cout << "Please enter a wage for a roll: ";
               while (true)
               {
                  //tempBet is used in calculating the players money by subtracting their money by their current bet
                  //tempBet2 is used to check the value of their bet with the new money, as to not change the bet in case it isnt allowed
                  //temp is used to be the input of the user to be added to tempBet2
                  int tempBet = bet;
                  int tempBet2 = bet;
                  int temp = 0;
                  cout << "Your current bet is " << bet << " and you have " << money << endl;
                  char userChar = ' ';
                  while (true)
                  {
                     cout << "Please enter a bet to make this more interesting. Enter 0 for no bet: ";
                     cin.ignore(256, '\n');
                     cin >> temp;
                     if (cin.fail())
                     {
                        cout << "Please enter an integer" << endl;
                        cin.clear();
                     }
                     else
                     {
                        break;
                     }
                  }
                  tempBet2 += temp;
                  if (temp == 0)
                  {
                     break;
                  }
                  else if (temp < 0)
                  {
                     cout << "Please have your bet be above 0" << endl;
                  }
                  else if (tempBet2 > money)
                  {
                     //See how their money is their money at the start of this round minus tempBet (the bet at the start of this turn)
                     cout << "Im sorry, but your bet for " << tempBet2 << " is more than your current left-over money, " << money - tempBet << " Please enter a lower bet amount." << endl;
                  }
                  else
                  {
                     bet = tempBet2;
                     break;
                  }
               }
               /*
					Rerolling Process
					*/
               di1 = rand() % 6 + 1;
               di2 = rand() % 6 + 1;
               diTotal = di1 + di2;
               cout << "Di 1 was " << di1 << " and Di 2 was " << di2 << " so your total is " << diTotal << " and you wanted " << point << endl
                    << endl;
               if (diTotal == 7)
               {
                  //Break is used here to get out of this while loop
                  break;
               }
            }
            //After the for loop, the user either has something that is equal to their point, or a 7
            if (diTotal == 7)
            {
               cout << "It seems your Di total was 7, sorry bro but you lose. you lost " << bet << " dollars" << endl;
               //Adjusts money accordingly
               money -= bet;
            }
            else
            {
               cout << "You win " << bet << " dollars! you rolled a " << diTotal << " and your point was " << point << endl;
               //Adjusts money accordingly
               money += bet;
            }
         }
         //This is where it asks the player to continue or not
         char userChar = ' ';
         while (userChar != 'y' && userChar != 'n')
         {
            cout << "Would you like to play another game? y/n: ";
            cin >> userChar;
         }
         if (userChar == 'y')
         {
            continue;
         }
         else
         {
            gameActive = false;
         }
      }
   }
}

/*
A player rolls two dice. Each die has six faces. These faces contain 1, 2, 3, 4, 5, and 6 spots.
After the dice have come to rest, the sum of the spots on the two upward faces is calculated. If
the sum is 7 or 11 on the first throw, the player wins. If the sum is 2, 3, or 12 on the first throw
(called "craps"), the player loses (i.e. the "house" wins). If the sum is 4, 5, 6, 8, 9, or 10 on the
first throw, then the sum becomes the player's "point." To win, you must continue rolling the dice
until you "make your point." The player loses by rolling a 7 before making the point.
*/
//If the sum is 7 or 11 on the first throw, the player wins
//if the sum is 2 3 or 12 on the first throw, house wins (Called craps)
//if the sum is 4 5 6 8 9 10, this number becomes their "point", continue till they reroll that number
//while rerolling for point, if they roll a 7, they lose