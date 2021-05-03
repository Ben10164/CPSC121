/*
Name: Ben Puryear
Class: CS 121 Fall 2020
Date: November 2nd, 2020
Programming Assignment: PA6
Description: This program computes and outputs a variety of calculations relating to GPA, student age and class standing uitilizing functions.
*/

#include <cmath>
#include <fstream>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>

using namespace std;

//Prototypes
double read_double(ifstream &infile);
int read_integer(ifstream &infile);
double calculate_sum(double num1, double num2, double num3, double num4, double num5);
double calculate_mean(double sum, int number);
double calculate_deviation(double number, double mean);
double calculate_variance(double deviation1, double deviation2, double deviation3, double deviation4, double deviation5, int number);
double calculate_standard_deviation(double variance);
double find_max(double num1, double num2, double num3, double num4, double num5);
double find_min(double num1, double num2, double num3, double num4, double num5);
void print_double(ofstream &outfile, double number);

int main()
{
   //Variables
   ifstream inputFile;
   ofstream outputFile;
   string trashbin = "";
   double GPAAverage = 0, classStandingMean = 0, ageMean = 0, GPAStandardDeviation = 0,
          GPAMin = 0, GPAMax = 0, GPATotal = 0, ageTotal = 0, yearTotal = 0, gpa1, gpa2,
          gpa3, gpa4, gpa5, age1, age2, age3, age4, age5, deviation1, deviation2, deviation3,
          deviation4, deviation5, variance;
   int trashbinInt = 0, year1, year2, year3, year4, year5;

   //Opens the input file
   inputFile.open("info.dat");
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
   if (outputFile.is_open())
   {
      cout << "Successfully opened output file" << endl;
   }
   else
   {
      cout << "Failed to open output file" << endl;
      exit(-1);
   }

   //Reads the first section
   trashbinInt = read_integer(inputFile);
   gpa1 = read_double(inputFile);
   year1 = read_integer(inputFile);
   age1 = read_double(inputFile);
   getline(inputFile, trashbin);

   //Reads the second section
   trashbinInt = read_integer(inputFile);
   gpa2 = read_double(inputFile);
   year2 = read_integer(inputFile);
   age2 = read_double(inputFile);
   getline(inputFile, trashbin);

   //Reads the third section
   trashbinInt = read_integer(inputFile);
   gpa3 = read_double(inputFile);
   year3 = read_integer(inputFile);
   age3 = read_double(inputFile);
   getline(inputFile, trashbin);

   //Reads the fourth section
   trashbinInt = read_integer(inputFile);
   gpa4 = read_double(inputFile);
   year4 = read_integer(inputFile);
   age4 = read_double(inputFile);
   getline(inputFile, trashbin);

   //Reads the fifth section
   trashbinInt = read_integer(inputFile);
   gpa5 = read_double(inputFile);
   year5 = read_integer(inputFile);
   age5 = read_double(inputFile);
   getline(inputFile, trashbin);

   //GPA
   GPATotal = calculate_sum(gpa1, gpa2, gpa3, gpa4, gpa5); //Calculates sum
   GPAAverage = calculate_mean(GPATotal, 5);               //Calculates average
   print_double(outputFile, GPAAverage);                   //Outputs

   //Class Standing
   yearTotal = calculate_sum(year1, year2, year3, year4, year5); //Calculates sum
   classStandingMean = calculate_mean(yearTotal, 5);             //Calculates average
   print_double(outputFile, classStandingMean);                  //Outputs

   //Age
   ageTotal = calculate_sum(age1, age2, age3, age4, age5); //Calculates sum
   ageMean = calculate_mean(ageTotal, 5);                  //Calculates average
   print_double(outputFile, ageMean);                      //Outputs

   //Calculates all the deviations
   deviation1 = calculate_deviation(gpa1, GPAAverage);
   deviation2 = calculate_deviation(gpa2, GPAAverage);
   deviation3 = calculate_deviation(gpa3, GPAAverage);
   deviation4 = calculate_deviation(gpa4, GPAAverage);
   deviation5 = calculate_deviation(gpa5, GPAAverage);

   //Outputs a new line to specify the new section in the output file
   outputFile << endl;

   //Uses all the deviations to calculate the variance
   variance = calculate_variance(deviation1, deviation2, deviation3, deviation4, deviation5, 5);

   //Uses the variance to calculate the standard deviation
   GPAStandardDeviation = calculate_standard_deviation(variance);

   //Outputs the standard deviation to the output file
   print_double(outputFile, GPAStandardDeviation);

   //Calculates the min
   GPAMin = find_min(gpa1, gpa2, gpa3, gpa4, gpa5);
   print_double(outputFile, GPAMin);

   //Calculates the max
   GPAMax = find_max(gpa1, gpa2, gpa3, gpa4, gpa5);
   print_double(outputFile, GPAMax);

   //Closes the files
   inputFile.close();
   outputFile.close();
}

//Functions
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

double calculate_sum(double num1, double num2, double num3, double num4, double num5)
{
   double sum = num1 + num2 + num3 + num4 + num5; //Calculates sum
   return sum;
}

double calculate_mean(double sum, int number)
{
   double mean = sum / number; //Calculates mean
   return mean;
}

double calculate_deviation(double number, double mean)
{
   double deviation = number - mean; //Calculates deviation
   return deviation;
}

double calculate_variance(double deviation1, double deviation2, double deviation3, double deviation4, double deviation5, int number)
{
   double variance = calculate_mean((pow(deviation1, 2) + pow(deviation2, 2) + pow(deviation3, 2) + pow(deviation4, 2) + pow(deviation5, 2)), number); //Calculates vairance
   return variance;
}

double calculate_standard_deviation(double variance)
{
   double standardDeviation = sqrt(variance); //Calculates standard deviation
   return standardDeviation;
}

double find_max(double num1, double num2, double num3, double num4, double num5)
{
   double max = num1;
   double nums[] = {num1, num2, num3, num4, num5};
   for (int i = 0; i < 5; i++)
   {
      if (nums[i] > max)
      { //Checks to see if the current number is larger than the max
         max = nums[i];
      }
   }
   return max;
}

double find_min(double num1, double num2, double num3, double num4, double num5)
{
   double min = num1;
   double nums[] = {num1, num2, num3, num4, num5};
   for (int i = 0; i < 5; i++)
   {
      if (nums[i] < min)
      { //Checks to see if the current number is smaller than the max
         min = nums[i];
      }
   }
   return min;
}

void print_double(ofstream &outfile, double number)
{
   outfile << fixed << setprecision(2) << number << endl; //Outputs the double
}