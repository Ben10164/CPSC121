#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	//string filename = "testfile.txt";
	//string inputText = "";
	//cout << "Please enter the amount of words: ";
	//int userInput;
	//cin >> userInput;
	//ifstream inputFile;
	//inputFile.open(filename);
	//if (!inputFile.is_open())
	//{
	//	cout << "File failed to open, exiting program..." << endl;
	//}
	//else if (inputFile.fail())
	//{
	//	cout << "File failed to open, exiting program..." << endl;
	//}
	//else
	//{
	//	while (userInput > 0)
	//	{
	//		getline(inputFile, inputText);
	//		if (inputFile.good())
	//		{
	//			cout << inputText << endl;
	//		}
	//		userInput--;
	//	}
	//	inputFile.close();
	//}

	int i = 0, j = 0, k = 0;
	i = 2;
	j = 3 + ++i;
	cout << j << endl;
	k = 3 + -i;
	cout << k << endl;
	i %= ++k + j--;
	cout << i << endl;
	i *= k-- + ++j;
	cout << i << endl
	return 0;
}