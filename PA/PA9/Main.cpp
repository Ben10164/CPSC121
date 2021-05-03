/*
Name: Ben Puryear
Class: CPSC 121
Due Date: 12/11/2020
Assignment: PA9
Use: This program completes all the requirements for PA9
Note: No sources
*/
#include "PA9.cpp"

int main()
{
   ifstream inputFile;
   ofstream outputFile;

   //Opens the input file
   inputFile.open("input.dat");
   if (inputFile.is_open())
   {
      cout << "Successfully opened input file" << endl;
   }
   else
   {
      cout << "Failed to open input file" << endl;
      exit(-1);
   }

   //Opens the output file
   outputFile.open("output.dat");
   if (inputFile.is_open())
   {
      cout << "Successfully opened output file" << endl;
   }
   else
   {
      cout << "Failed to open output file" << endl;
      exit(-1);
   }

   // creates vectors
   vector<string> id(0);
   vector<double> gpa(0);
   vector<int> year(0);
   vector<double> age(0);

   // gets data for the vectors
   store_data_sets(inputFile, id, gpa, year, age);

   // computes and outputs said data
   outputStuff(id, gpa, year, age, outputFile);

   inputFile.close();
   outputFile.close();
}
