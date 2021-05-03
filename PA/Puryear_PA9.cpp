/*
Name: Ben Puryear
Class: CPSC 121
Due Date: 12/11/2020
Assignment: PA9
Use: This program completes all the requirements for PA9
Note: No sources
*/
//includes
#include <array>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

//namespace
using namespace std;

//function prototypes
string find_ID(vector<double> gpa, vector<string> id, double num);
double read_double(ifstream &infile);
int read_integer(ifstream &infile);
string read_string(ifstream &infile);
int store_data_sets(ifstream &infile, vector<string> &id, vector<double> &gpa, vector<int> &year, vector<double> &age);
double calculate_sum(vector<int> year);
double calculate_sum(vector<double> v1);
double calculate_mean(double sum, int number);
int calculate_count_above_mean(double mean, vector<double> gpa);
int calculate_count_below_mean(double mean, vector<double> gpa);
vector<double> calculate_deviation(double mean, vector<double> v1);
double calculate_variance(vector<double> v1);
double calculate_standard_deviation(double variance);
double find_max(vector<double> v1);
double find_max(vector<int> v1);
double find_min(vector<double> v1);
double find_min(vector<int> v1);
void print_formatted_double(ofstream &outfile, double number, int precision);
void outputStuff(vector<string> id, vector<double> gpa, vector<int> year, vector<double> age, ofstream &outputFile);

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

   vector<string> id(0);
   vector<double> gpa(0);
   vector<int> year(0);
   vector<double> age(0);

   store_data_sets(inputFile, id, gpa, year, age);

   outputStuff(id, gpa, year, age, outputFile);

   inputFile.close();
   outputFile.close();
}

string find_ID(vector<double> gpa, vector<string> id, double num)
{
   for (int i = 0; i < gpa.size(); i++)
   {
      if (num == gpa[i])
      {
         return id[i];
      }
   }
   return "";
}

double read_double(ifstream &infile)
{
   double read = 0;
   string trashbin = "";
   infile >> read;
   getline(infile, trashbin); //Finishes the line
   return read;
}

int read_integer(ifstream &infile)
{
   int read = 0;
   string trashbin = "";
   infile >> read;
   getline(infile, trashbin); //Finishes the line
   return read;
}

string read_string(ifstream &infile)
{
   string read = "";
   getline(infile, read);
   return read;
}

int store_data_sets(ifstream &infile, vector<string> &id, vector<double> &gpa, vector<int> &year, vector<double> &age)
{
   int records = 0;
   while (!infile.eof())
   {
      string trashbin = "";

      if (records > 0)
      {
         //empty line
         getline(infile, trashbin);
      }
      //id
      id.push_back(read_string(infile));
      if (infile.fail())
      {
         return -1;
      }
      //gpa
      gpa.push_back(read_double(infile));
      if (infile.fail())
      {
         return -1;
      }
      //year
      year.push_back(read_integer(infile));
      if (infile.fail())
      {
         return -1;
      }
      //age
      age.push_back(read_double(infile));
      if (infile.fail())
      {
         return -1;
      }
      records++;
   }
   return records;
}

double calculate_sum(vector<int> year)
{
   double sum = 0;
   for (int i = 0; i < year.size(); i++)
   {
      sum += year[i];
   }
   return sum;
}

double calculate_sum(vector<double> v1)
{
   double sum = 0;
   for (int i = 0; i < v1.size(); i++)
   {
      sum += v1[i];
   }
   return sum;
}

double calculate_mean(double sum, int number)
{
   if (number == 0)
   {
      cout << "A bug has occured uh oh" << endl;
      return -1;
   }
   double mean = sum / number; //Calculates mean
   return mean;
}

int calculate_count_above_mean(double mean, vector<double> gpa)
{
   int above = 0;
   for (double x : gpa)
   {
      if (x > mean)
      {
         above++;
      }
   }
   return above;
}

int calculate_count_below_mean(double mean, vector<double> gpa)
{
   int below = 0;
   for (double x : gpa)
   {
      if (x < mean)
      {
         below++;
      }
   }
   return below;
}

vector<double> calculate_deviation(double mean, vector<double> v1)
{
   vector<double> temp(0);
   for (int i = 0; i < v1.size(); i++)
   {
      temp.push_back(v1[i] - mean);
   }
   return temp;
}

double calculate_variance(vector<double> v1)
{
   double sum = 0;
   for (int i = 0; i < v1.size(); i++)
   {
      sum += pow(v1[i], 2);
   }
   double variance = calculate_mean(sum, v1.size());
   return variance;
}

double calculate_standard_deviation(double variance)
{
   double standardDeviation = sqrt(variance); //Calculates standard deviation
   return standardDeviation;
}

double find_max(vector<double> v1)
{
   double max = v1[0];
   for (int i = 0; i < v1.size(); i++)
   {
      if (v1[i] >= max)
      {
         max = v1[i];
      }
   }
   return max;
}
double find_max(vector<int> v1)
{
   int max = v1[0];
   for (int i = 0; i < v1.size(); i++)
   {
      if (v1[i] >= max)
      {
         max = v1[i];
      }
   }
   return max;
}

double find_min(vector<double> v1)
{
   double min = v1[0];
   for (int i = 0; i < v1.size(); i++)
   {
      if (v1[i] <= min)
      {
         min = v1[i];
      }
   }
   return min;
}
double find_min(vector<int> v1)
{
   int min = v1[0];
   for (int i = 0; i < v1.size(); i++)
   {
      if (v1[i] <= min)
      {
         min = v1[i];
      }
   }
   return min;
}

void print_formatted_double(ofstream &outfile, double number, int precision)
{
   outfile << fixed << setprecision(precision) << number << endl;
}

void outputStuff(vector<string> id, vector<double> gpa, vector<int> year, vector<double> age, ofstream &outputFile)
{
   outputFile << gpa.size() << endl;

   outputFile << endl;

   double gpaSum = calculate_sum(gpa);

   double gpaMean = calculate_mean(gpaSum, gpa.size());
   print_formatted_double(outputFile, gpaMean, 2);

   int gpaAbove = calculate_count_above_mean(gpaMean, gpa);
   outputFile << gpaAbove << endl;
   int gpaBelow = calculate_count_below_mean(gpaMean, gpa);
   outputFile << gpaBelow << endl;

   double yearSum = calculate_sum(year);
   double yearMean = calculate_mean(yearSum, year.size());
   print_formatted_double(outputFile, yearMean, 2);
   double ageSum = calculate_sum(age);
   double ageMean = calculate_mean(ageSum, age.size());
   print_formatted_double(outputFile, ageMean, 2);

   outputFile << endl;

   vector<double> deviations = calculate_deviation(gpaMean, gpa);
   double variance = calculate_variance(deviations);
   double sD = calculate_standard_deviation(variance);
   print_formatted_double(outputFile, sD, 2);

   double gpaMin = find_min(gpa);
   outputFile << gpaMin << endl;
   string gpaMinID = find_ID(gpa, id, gpaMin);
   outputFile << gpaMinID << endl;
   double gpaMax = find_max(gpa);
   outputFile << gpaMax << endl;
   string gpaMaxID = find_ID(gpa, id, gpaMax);
   outputFile << gpaMaxID << endl;
}