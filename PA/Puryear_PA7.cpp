/*
Name: Ben Puryear
Class: CPSC 121
Due Date: 11/13/2020
Assignment: PA7
Use: This program completes all the requirements for PA5 by analyzing a roadtrip
Note: Used stack exchange to find the strcpy_s function
*/
#include <array>
#include <cmath>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

bool determineGame(char visibleLetters[100], char wordchar[100], int length);
void checkAvailableLetters(char (&availableLetters)[26], int guess);
void checkHiddenLetters(char (&wordchar)[100], char (&visibleLetters)[100], int guess, bool &didChange);
void checkAndMakeChangesToArray(char (&wordchar)[100], char (&visibleLetters)[100], char (&availableLetters)[26], int guess, bool &didChange);
void openFile(ifstream &inputFile);
void readFile(ifstream &inputFile, string word, string (&words)[100], int &index);
void createAvailableLetters(char (&availableLetters)[26], char &letter);
void createVisibleLetters(char (&visibleLetters)[100], int &length);
void mainLoop(int &guesses, bool &goodGame, char (&visibleLetters)[100], char (&wordchar)[100], int &length, char (&availableLetters)[26], char &guess, bool &didChange);
void judgeGame(bool &goodGame, string &word);
void createWord(int &indexrandom, int &index, string &word, string (&words)[100]);

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

bool determineGame(char visibleLetters[100], char wordchar[100], int length)
{
   for (int i = 0; i < length; i++)
   {
      if (wordchar[i] != visibleLetters[i])
      {                // Sees if all of the visible letters are the same as the regular word
         return false; // Uh oh there is a difference in the arrays! Return false
      }
   }
   return true; // For it to get here, it means the arrays are the exact same
}

void checkAndMakeChangesToArray(char (&wordchar)[100], char (&visibleLetters)[100], char (&availableLetters)[26], int guess, bool &didChange)
{
   checkAvailableLetters(availableLetters, guess);                 // Checks the available letters
   checkHiddenLetters(wordchar, visibleLetters, guess, didChange); // Checks the hidden letters
}

void checkAvailableLetters(char (&availableLetters)[26], int guess)
{
   for (int i = 0; i < 26; i++)
   { // Checks to see if the guessed character is available in the words list
      if (guess == availableLetters[i])
      {                             // The guessed char is in the list of unguessed char
         availableLetters[i] = ' '; // Replaces the char with an empty spot
         break;
      }
   }
}

void checkHiddenLetters(char (&wordchar)[100], char (&visibleLetters)[100], int guess, bool &didChange)
{
   for (int i = 0; i < sizeof(wordchar); i++)
   {
      if (guess == wordchar[i])
      {                             // Sees if the guessed char is in the word to guess
         visibleLetters[i] = guess; // Since it is a correct guess, it changes the visible letters
         didChange = true;          // It is in it, and something did change, so changes the boolean
      }
   }
}

void openFile(ifstream &inputFile)
{
   inputFile.open("words.txt"); //opens the file
   if (inputFile.is_open())
   { // checks if the file is open
      cout << "successfully opened input file" << endl;
   }
   else
   {
      cout << "failed to open input file" << endl;
      exit(-1);
   }
}

void readFile(ifstream &inputFile, string word, string (&words)[100], int &index)
{
   while (!inputFile.eof())
   { // Starts the loop to read in the files
      word = "";
      getline(inputFile, word);
      words[index] = word; // Adds the string from the file to the string array of words
      index++;
   }
}

void createAvailableLetters(char (&availableLetters)[26], char &letter)
{
   letter = 'a';
   for (int i = 0; i < 26; i++)
   { // This is making the available letters array the alphabet
      availableLetters[i] = letter;
      letter++;
   }
}

void createVisibleLetters(char (&visibleLetters)[100], int &length)
{
   for (int i = 0; i < length; i++)
   { // Makes the array for the hidden word be a - per character in the word
      visibleLetters[i] = '-';
   }
}

void mainLoop(int &guesses, bool &goodGame, char (&visibleLetters)[100], char (&wordchar)[100], int &length, char (&availableLetters)[26], char &guess, bool &didChange)
{
   guesses = 7;
   while (true)
   { // Starts the while loop, this is the while loop that continues until the game ends
      if (guesses == 0)
      { // If the character runs out of guesses, break
         break;
      }
      goodGame = determineGame(visibleLetters, wordchar, length); // Does the determineGame function
      if (goodGame)
      {         // goodGame represents if the game has been won
         break; // If the game was won, then break
      }

      for (int i = 0; i < length; i++)
      { // Outputs the hidden words array
         cout << visibleLetters[i];
      }

      cout << endl; // Outputs an empty line

      cout << "Available letters: "; // Starts the line of the available letters

      for (int i = 0; i < 26; i++)
      {                               // Starts the loop to output the available letters
         cout << availableLetters[i]; // Outputs the letters in the available letters
      }

      cout << endl; // Outputs an empty line

      cout << guesses << " incorrect remaining." << endl; // Lives remaining
      cout << "Please enter your guess: ";                // Asks for the users guess
      cin >> guess;                                       // Uses the users input and assigns it to the char guess

      didChange = false; // Assigns the didChange boolean to false before ths start of the loop
      checkAndMakeChangesToArray(wordchar, visibleLetters, availableLetters, guess, didChange);

      if (didChange)
      { // Dependong on if something changed, it will either output a correct or incorrect
         cout << "Nice! " << guess << " is in the word." << endl;
      }
      else
      {
         guesses--;
         cout << guess << " is not in the word. You have " << guesses << " incorrect guesses remaining." << endl;
      }

      cout << endl; // Outputs an empty line
   }
}
void judgeGame(bool &goodGame, string &word)
{
   if (goodGame)
   {
      cout << "Congrats, you guessed the word " << word << "!" << endl;
   }
   else
   {
      cout << "Sorry you lost, the correct answer was " << word << endl;
   }
}
void createWord(int &indexrandom, int &index, string &word, string (&words)[100])
{
   indexrandom = rand() % index + 1; // Calculates a random number in the index range of the words
   word = words[indexrandom];        // Makes the string word a string from the words array using the index previously calculated
}