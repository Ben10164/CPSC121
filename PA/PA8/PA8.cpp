/*
Name: Ben Puryear
Class: CPSC 121
Due Date: 11/20/2020
Assignment: PA8
Use: This program completes all the requirements for PA8 by doing a game of battleship
Note: No sources
*/
#include "PA8.h"
void usersTurn(char board[NUM_ROWS][NUM_COLS], char boardComp[NUM_ROWS][NUM_COLS], char boardVisibleComp[NUM_ROWS][NUM_COLS], int& userHits, bool& gameActive, ofstream& outputFile, int userTurns) {
	int x = 0;
	int y = 0;
	cout << "Your board" << endl;
	printArray(board, NUM_ROWS, NUM_COLS);
	cout << "Enemies board" << endl;
	printArray(boardVisibleComp, NUM_ROWS, NUM_COLS);

	cout << "Please enter a guess in an y x format: ";
	cin >> x; // Gets the input
	cin >> y; // Gets the input


	outputFile << "Player 1: ";
	outputFile << y << " " << x << " "; // Outputs the stats


	if (boardComp[x][y] != '-') {
		cout << "HIT!" << endl;
		outputFile << "\"Hit\"" << endl;
		userHits++; // Adds to the tally of user hits
		boardVisibleComp[x][y] = '*'; // If they hit, then the guess spot is replaced with '*'
	}
	else {
		cout << "Miss" << endl;
		outputFile << "\"Miss\"" << endl;
		boardVisibleComp[x][y] = ' '; // If they miss, then the guess spot is replaced with ' '
	}

	if (userHits == 17) { // Checks if someone won
		gameActive = false;
	}
}

void compTurn(char board[NUM_ROWS][NUM_COLS], char boardComp[NUM_ROWS][NUM_COLS], char boardVisibleComp[NUM_ROWS][NUM_COLS], int& compHits, bool& gameActive, ofstream& outputFile, int enemyTurns) {
	int x = 0;
	int y = 0;

	while (true) {
		x = rand() % 10;
		y = rand() % 10;
		if (board[x][y] != ' ') {
			break;
		}
	}

	outputFile << "Player 2: ";
	outputFile << y << " " << x;
	cout << "The computer guessed " << y << " " << x << endl; // Outputs the stats

	if (board[x][y] != '-') { // If it is not an unused spot
		cout << "HIT!" << endl;
		outputFile << "\"Hit\"" << endl;
		compHits++; // Adds one to the tally of hits
		board[x][y] = '*'; // If they hit, the guess spot is marked with '*'
	}
	else {
		cout << "They Missed" << endl;
		outputFile << "\"Miss\"" << endl;
		board[x][y] = ' '; // If they miss, then the guess spot is replaced with ' '
	}

	if (compHits == 17) {
		gameActive = false; // This means someone won
	}

}
void manuallyPlaceShipsOnBoard(char grid[NUM_ROWS][NUM_COLS]) {
	for (int i = 0; i <= 4; i++) {
		int x1, x2, x3, x4, x5, //
			y1, y2, y3, y4, y5; // Variables
		int temp[10];
		while (true) {
			printArray(grid, NUM_ROWS, NUM_COLS);
			cout << "Please enter (top to bottom, left to right [smallest to largest]) the " << shipSizes[i] << " x y coordinates for the " << shipNames[i] << " (x1 y1 x2 y2 ...): ";
			for (int k = 0; k < shipSizes[i] * 2; k++) {
				cin >> temp[k];
			}
			bool onTop = false;
			if (temp[0] == temp[2]) {
				for (int j = temp[1]; j <= temp[shipSizes[i] * 2 - 1]; j++) {
					if (grid[j][temp[0]] != '-') { // Checks to see if the spot the ship will be placed on is available
						onTop = true; // Uh oh
					}
				}
			}
			else if (temp[1] == temp[3]) {
				for (int j = temp[0]; j <= temp[shipSizes[i] * 2 - 2]; j++) {
					if (grid[temp[1]][j] != '-') { // Checks to see if the spot the ship will be placed on is available
						onTop = true; // Nooo
					}
				}
			}
			if (!onTop && ((temp[0] == temp[2]) || (temp[1] == temp[3]))) {
				break; // This means it is completely valid
			}
			else {
				cout << "That ship is actually on top of another ship, sorry" << endl;
			}
		}

		if (temp[0] == temp[2]) {
			for (int j = temp[1]; j <= temp[shipSizes[i] * 2 - 1]; j++) {
				grid[j][temp[0]] = shipSymbols[i]; // Does the act of changing the array
			}
		}
		else if (temp[1] == temp[3]) {
			for (int j = temp[0]; j <= temp[shipSizes[i] * 2 - 2]; j++) {
				grid[temp[1]][j] = shipSymbols[i]; // Does the act of changing the array
			}
		}
	}
}

bool realShip(char grid[NUM_ROWS][NUM_COLS], int temp[10], int i) {
	bool x = true;
	bool y = true;
	for (int p = 0; p <= shipSizes[i] * 2 - 2; p += 2) {
		if (temp[p] != temp[p + 2]) {
			x = false; // False if one of the inputed coords does not match with the previous coord to make a straight line
		}
	}
	for (int p = 1; p <= shipSizes[i] * 2 - 1; p += 2) {
		if (temp[p] != temp[p + 2]) {
			y = false; // False if one of the inputed coords does not match with the previous coord to make a straight line
		}
	}
	if (x || y) { // If any of the tests failed to return false, return true
		return true;
	}
}

bool seeIfAvailable(int temp[10], char grid[NUM_ROWS][NUM_COLS], int i) {
	if (temp[0] == temp[2]) {
		for (int j = temp[1]; j <= temp[shipSizes[i] * 2 - 1]; j++) {
			if (grid[j][temp[0]] != '-') { // Checks to see if the spot does not equal '-'
				return false; // Uh oh its false
			}
		}
	}
	else if (temp[1] == temp[3]) {
		for (int j = temp[0]; j <= temp[shipSizes[i] * 2 - 2]; j++) {
			if (grid[temp[1]][j] != '-') { // Checks to see if the spot does not equal '-'
				return false; // Uh oh its false
			}
		}
	}
	return true; // At this point, none of the coords that the ship will be added on are anything besides '-', so its an available spot, returning true
}

void randomlyPlaceShipsOnBoard(char grid[NUM_ROWS][NUM_COLS]) {
	while (true) { // This continues to repeat until you get a valid ship sequence
		for (int i = 0; i < 5; i++) { // The five ships
			while (true) { // This continues until a ship is valid
				int randY = rand() % 10; // Generates the random Y value
				int randX = rand() % 10; // Generates the random X value
				int randDir = rand() % 4 + 1; // Generates the random direction (1,2,3,4)
				if (randDir == 1) { // up
					if (!(shipSizes[i] - randY < 0)) { // If adding the ships size upwards fits
						for (int j = randY; j < shipSizes[i] + randY; j++) {
							grid[j][randX] = shipSymbols[i]; // Sets the values
						}
						break;
					}
				}
				if (randDir == 2) { // right
					if (!(randX + shipSizes[i] >= 10)) { // If adding the ships size rightwards fits
						for (int j = randX; j < shipSizes[i] + randX; j++) {
							grid[randY][j] = shipSymbols[i]; // Sets the values
						}
						break;
					}
				}
				if (randDir == 3) { // down
					if (!(randY + shipSizes[i] >= 10)) { // If adding the ships size downwards fits
						for (int j = shipSizes[i] - randY; j > randY; j--) {
							grid[j][randX] = shipSymbols[i]; // Sets the values
						}
						break;
					}
				}
				if (randDir == 4) { // left
					if (!(shipSizes[i] - randX < 0)) { // If adding the ships size leftwards fits
						for (int j = shipSizes[i] - randX; j > randX; j--) {
							grid[randY][j] = shipSymbols[i]; // Sets the values
						}
						break;
					}
				}
			}
		}
		int count = 0; // Initializes count
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (grid[i][j] == '-') {
					count++; // This counts the amount of dashes in the array
				}
			}
		}
		if (count == 83) { // If the amount of dashes is 83, this means a winner is declared
			break;
		}
		fillArray(grid, NUM_ROWS, NUM_COLS);
	}
}

void welcomeScreen() {
	cout << "Welcome to battleship" << endl;
	cout << "" << endl;
	system("pause");
	cout << "" << endl;
}

int selectWhoStartsFirst(int firstAns, int& random) {
	random = rand() % 2 + 1; // Random number to decide who is going first
	if (random == 1) {
		cout << "Player 1 is  going first" << endl;
	}
	if (random == 2) {
		cout << "Player 2 is going first" << endl;
	}
	return random;
}

void fillArray(char grid[NUM_ROWS][NUM_COLS], int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			grid[i][j] = '-'; // Fills the array with '-' on both dimensions
		}
	}
}

void printArray(const char grid[NUM_ROWS][NUM_COLS], int rows, int cols) {
	cout << endl;
	for (int i = -1; i < rows; i++) {
		if (i > -1) {
			cout << i << " "; // Prints the row numbers
		}
		for (int j = 0; j < cols; j++) {
			if (j == 0 && i == -1) {
				cout << "  ";
				for (int k = 0; k < 10; k++) {
					cout << k << " "; // Prints the column numbers
				}
			}
			else {
				if (i >= 0) {
					cout << grid[i][j] << " "; // Prints the actual array
				}
			}
		}
		cout << endl;
	}
}