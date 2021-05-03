/*
Name: Ben Puryear
Class: CPSC 121
Due Date: 11/20/2020
Assignment: PA8
Use: This program completes all the requirements for PA8 by doing a game of battleship
Note: No sources
*/
#ifndef PA8_H
#define PA8_H
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

//constant global variables
const int NUM_ROWS = 10, NUM_COLS = 10;
const string shipNames[] = { "carrier", "battleship", "cruiser", "submarine", "destroyer" };
const char shipSymbols[] = { 'c', 'b', 'r', 's', 'd' };
const int shipSizes[] = { 5, 4, 3, 3, 2 };

//function prototypes
void welcomeScreen();
void fillArray(char grid[NUM_ROWS][NUM_COLS], int rows, int cols);
void printArray(const char grid[NUM_ROWS][NUM_COLS], int rows, int cols);
int selectWhoStartsFirst(int firstAns, int& random);
void manuallyPlaceShipsOnBoard(char grid[NUM_ROWS][NUM_COLS]);
void randomlyPlaceShipsOnBoard(char grid[NUM_ROWS][NUM_COLS]);
void usersTurn(char board[NUM_ROWS][NUM_COLS], char boardComp[NUM_ROWS][NUM_COLS], char boardVisibleComp[NUM_ROWS][NUM_COLS], int& userHits, bool& gameActive, ofstream& outputFile, int userTurns);
void compTurn(char board[NUM_ROWS][NUM_COLS], char boardComp[NUM_ROWS][NUM_COLS], char boardVisibleComp[NUM_ROWS][NUM_COLS], int& compHits, bool& gameActive, ofstream& outputFile, int enemyTurns);

#endif