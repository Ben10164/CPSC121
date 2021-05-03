/*
Name: Ben Puryear
Class: CPSC 121
Due Date: 12/11/2020
Assignment: PA9
Use: This program completes all the requirements for PA9
Note: No sources
*/
#ifndef PA9_H
#define PA9_H
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

#endif