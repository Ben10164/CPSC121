#include <iostream> //needed for cin/cout
#include <string> //needed for string functions, e.g. getline
#include <fstream> //needed for file IO
#include <iomanip> //needed for output formatting
#include <ios> //needed for output formatting

using namespace std;

int main() {
	string description = "", endMessage = "", trashbin = "";
	string inputFilename = "datafile.dat", outputFilename = "output.txt";
	double score = 0.0, averageScore = 0.0;
	int sumStanding = 0, recordCount = 0, intTrashbin = 0;
	ifstream infile;
	ofstream outfile;
	//open our input file
	infile.open(inputFilename);
	outfile.open(outputFilename);
	//make sure the file is open
	if (!infile.is_open()) {
		cout << "The file was not opened" << endl;
		return -1;
	}
	//read in the description
	getline(infile, description);
	//there's a newline
	getline(infile, trashbin); //or temp idk


	//now we read in the repeating portion of the file
	while (!infile.eof()) {


		/*
			input file format for this section
			string | Full name
			integer | ID number
			double | Score
			integer | Standing
			newline | {REPEAT the last 4 lines an --unknown-- number of times}
		*/
		//assume there's at least 1 set of data here
		getline(infile, trashbin); //we are not doing anything with the name but we have to read it anyways

		//option 1 -- NOTE: this is very situational, we may not know what this is!
		if (trashbin == "*End of list*") { //cheks to see if we are at the end
			cout << "We are done" << endl;
			endMessage = trashbin;
			break;
		}
		infile >> intTrashbin; //we are not doing anything with the ID but we have to read it anyways

		//option 2
		//failed to store into the integer
		if (infile.fail()) {
			cout << "We are done" << endl;
			endMessage = trashbin;
			break;
		}

		//possible newline in the buffer
		infile >> score;
		averageScore += score;

		infile >> intTrashbin; //temporarily reading into this variable before we sum
		sumStanding += intTrashbin; //accumulating -- adding the new value to the sum
		getline(infile, trashbin); //this is getting the rest of the line, that presky end of line
		getline(infile, trashbin); //there is also a newline between data sets

		//increment records read count
		recordCount++;

		/*
			Two options to detect end of record set.
			1. the name record is our "end of file" message
			2. If we can't use that then we can check if infile.fail() flag has been tripped
		*/
	}

	averageScore = averageScore / recordCount;
//output
	outfile << "Description: " << description << endl;
	outfile << "Average Score: " << fixed << setprecision(2) << averageScore << endl;
	outfile << "Sun of Standing: " << sumStanding << endl;
	outfile << "Number of record read: " << recordCount << endl;

//close our files
	infile.close();
	outfile.close();

return 0;
}
