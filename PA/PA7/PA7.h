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
#ifndef PA7_H
#define PA7_H
//includes
#include <iostream>
#include <array>
#include <iomanip>
#include <string>
#include <cstring>
#include <ios>
#include <cmath>
#include <fstream>
#include <stdio.h>
//namespace
using namespace std;
//prototypes
bool determineGame(char visibleLetters[100], char wordchar[100], int length);
void checkAvailableLetters(char(&availableLetters)[26], int guess);
void checkHiddenLetters(char(&wordchar)[100], char(&visibleLetters)[100], int guess, bool& didChange);
void checkAndMakeChangesToArray(char(&wordchar)[100], char(&visibleLetters)[100], char(&availableLetters)[26], int guess, bool& didChange);
void openFile(ifstream& inputFile);
void readFile(ifstream& inputFile, string word, string(&words)[100], int& index);
void createAvailableLetters(char(&availableLetters)[26], char& letter);
void createVisibleLetters(char(&visibleLetters)[100], int& length);
void mainLoop(int& guesses, bool& goodGame, char(&visibleLetters)[100], char(&wordchar)[100], int& length, char(&availableLetters)[26], char& guess, bool& didChange);
void judgeGame(bool& goodGame, string& word);
void createWord(int& indexrandom, int& index, string& word, string(&words)[100]);
#endif