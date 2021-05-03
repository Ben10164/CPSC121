#include <iostream>
#include <string>
#include <fstream>


using namespace std;

int main()
{
	string filename = "words.txt";

	string filenameOut = "words_copy.txt";

	string inputText = "";
	int count = 1;

	ifstream inputFile;
	ofstream outputFile;

	inputFile.open(filename);
	outputFile.open(filenameOut);

	if (!inputFile.is_open())
	{
		cout << "File failed to open, exiting program..." << endl;
	}
	else if (inputFile.fail())
	{
		cout << "File failed to open, exiting program..." << endl;
	}
	else
	{
		while (!inputFile.eof())
		{
			getline(inputFile, inputText);

			if (inputFile.good())
			{
				outputFile << inputText << endl;
			}
		}
		cout << "Done!" << endl;

		inputFile.close();
		outputFile.close();
	}
	return 0;
}