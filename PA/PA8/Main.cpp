/*
Name: Ben Puryear
Class: CPSC 121
Due Date: 11/20/2020
Assignment: PA8
Use: This program completes all the requirements for PA8 by doing a game of battleship
Note: No sources
*/
#include "PA8.cpp"

int main()
{
   srand(time(0));

   char board[NUM_ROWS][NUM_COLS];
   char boardComp[NUM_ROWS][NUM_COLS];
   char boardVisibleComp[NUM_ROWS][NUM_COLS];
   int enemyHits = 0, userHits = 0, userTurns = 0, enemyTurns = 0, userMisses, enemyMisses, firstAns = 0, random = 0;
   double userRatio, enemyRatio;
   bool gameActive = true;
   char input = ' ';
   ofstream outputFile;

   outputFile.open("battleship.log"); // Opens file
   if (outputFile.is_open())
   { // Checks if file is open
      cout << "Successfully opened input file" << endl;
   }
   else
   {
      cout << "Failed to open input file" << endl; // Uh oh, the file couldn't be opened
      exit(-1);
   }

   srand(time(NULL)); // Makes the random seed

   welcomeScreen(); // Calls the welcome screen function

   // Fills all 3 boards
   fillArray(board, NUM_ROWS, NUM_COLS);

   fillArray(boardComp, NUM_ROWS, NUM_COLS);

   fillArray(boardVisibleComp, NUM_ROWS, NUM_COLS);

   randomlyPlaceShipsOnBoard(boardComp); // Fills the opponents board with random ships

   cout << "Would you like to place your boats randomly or manually? (r or m): ";
   while (true)
   { // Repeats until a valid answer
      cin >> input;
      if (input == 'r')
      {
         break;
      }
      else if (input == 'm')
      {
         break;
      }
      else
      {
         cout << "Please enter a r or m" << endl;
      }
   }
   if (input == 'm')
   { // If they inputed m, manually select the ships
      manuallyPlaceShipsOnBoard(board);
   }
   else
   { // Otherwise, just randomly select their ship
      cout << "Here is your random board" << endl;
      randomlyPlaceShipsOnBoard(board);
      printArray(board, NUM_ROWS, NUM_COLS);
   }

   system("pause");

   selectWhoStartsFirst(firstAns, random); // Selects who goes first

   if (random == 1)
   { // If random == 1, it means the player goes first
      while (true)
      {
         enemyTurns++; // Adds to the computer turn counter
         usersTurn(board, boardComp, boardVisibleComp, userHits, gameActive, outputFile, userTurns);
         if (gameActive == false)
         {
            break;
         }
         userTurns++; // Adds to the user turn counter
         compTurn(board, boardComp, boardVisibleComp, enemyHits, gameActive, outputFile, enemyTurns);
         if (gameActive == false)
         { // Uh oh the game is over now
            break;
         }
      }
   }
   else
   { // Otherwise the computer goes first
      while (true)
      {
         enemyTurns++; // Adds to the computer turn counter
         compTurn(board, boardComp, boardVisibleComp, enemyHits, gameActive, outputFile, enemyTurns);
         if (gameActive == false)
         {
            break;
         }
         userTurns++; // Adds to the user turn counter
         usersTurn(board, boardComp, boardVisibleComp, userHits, gameActive, outputFile, userTurns);
         if (gameActive == false)
         {
            break;
         }
      }
   }
   // For it to get here, the game must be over, resulting in one side winning
   if (userHits > enemyHits)
   { // If you have more hits than the enemy, you win
      cout << "You won" << endl;
   }
   else
   { // Otherwise you lose
      cout << "You lost" << endl;
   }

   // MAKE IT SO AFTER EVERY TURN IT OUTPUTS TO FILE

   userMisses = userTurns - userHits;
   enemyMisses = enemyTurns - enemyHits;
   userRatio = static_cast<double>(userHits) / userMisses;
   enemyRatio = static_cast<double>(enemyHits) / enemyMisses;

   /*
				This is all the output file stuff, pretty self explanatory
	*/
   outputFile << "Player 1 stats: " << endl;
   outputFile << "Number Hits: " << userHits << endl;
   outputFile << "Number Misses: " << userMisses << endl;
   outputFile << "Total Shots: " << userTurns << endl;
   outputFile << "Hit/Miss Ratio: " << userRatio * 100 << "%" << endl;
   if (userHits > enemyHits)
   {
      outputFile << "Won the game" << endl;
   }
   else
   {
      outputFile << "Lost the game" << endl;
   }
   outputFile << " ------------------ " << endl
              << endl;

   outputFile << "Player 2 stats: " << endl;
   outputFile << "Number Hits: " << enemyHits << endl;
   outputFile << "Number Misses: " << enemyMisses << endl;
   outputFile << "Total Shots: " << enemyTurns << endl;
   outputFile << "Hit/Miss Ratio: " << enemyRatio * 100 << "%" << endl;
   if (userHits < enemyHits)
   {
      outputFile << "Won the game" << endl;
   }
   else
   {
      outputFile << "Lost the game" << endl;
   }
   outputFile << " ------------------ " << endl
              << endl;

   outputFile.close(); // Closes the output file
   return 0;
}