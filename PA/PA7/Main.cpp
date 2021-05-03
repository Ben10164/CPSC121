/*
Name: Ben Puryear
Class: CPSC 121
Due Date: 11/13/2020
Assignment: PA7
Use: This program completes all the requirements for PA5 by analyzing a roadtrip
Note: Used stack exchange to find the strcpy_s function
*/

/*
						DID THE EXTRA CREDIT
*/
#include "PA7.cpp"
int main()
{
   // Variables
   ifstream inputFile;
   string word = "";
   string words[100];
   char visibleLetters[100], wordchar[100], availableLetters[26];
   int length = 0, indexrandom = 0, index = 0, guesses = 7;
   char letter = 'a', guess, playAgain = ' ';
   bool goodGame = false, didChange;

   srand(time(0)); // Does the random seed

   openFile(inputFile); // Opens the file

   readFile(inputFile, word, words, index); // Reads the file
   while (true)
   {
      createWord(indexrandom, index, word, words); // Creates the word to be guessed

      length = word.size();           // Calculates the length of the word to be guessed
      strcpy(wordchar, word.c_str()); // Copies the word to be guessed into the new array of characters

      //cout << word << endl; // USE THIS FOR DEBUG

      createAvailableLetters(availableLetters, letter); // Creates the available letters array

      createVisibleLetters(visibleLetters, length); // Creates the visible letters array

      cout << "You word to guess has " << length << " letters. " << endl
           << endl; // Outputs the length of the word

      mainLoop(guesses, goodGame, visibleLetters, wordchar, length, availableLetters, guess, didChange); // Does the actual loop of hangman

      judgeGame(goodGame, word); // Judges if they won or not

      cout << endl
           << "wanna play again (n to quit, any other character for continue): ";
      playAgain = ' ';
      cin >> playAgain;
      if (playAgain == 'n')
      {
         break;
      }
   }

   inputFile.close(); // Closes file
   return 0;
}