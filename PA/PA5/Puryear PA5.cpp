/*
Name: Ben Puryear
Class: CPSC 121
Due Date: 10/19/2020
Assignment: PA5
Use: This program completes all the requirements for PA5 by analyzing a roadtrip
Note: No further notes
*/

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
   ifstream inputFile;
   ofstream outputFile;
   string startingLocation = "", trashbin = "", location = "", temp = "", longestDisatanceName = "", longestDaysName = "",
          longestDistanceNameBefore = "", input = "puryear_roadtrip.txt", output = "puryear_roadtrip_stats.txt", finalDestination = "";
   int daysSpent = 0, numWaypoints = 0, totalDays = 0, totalMiles = 0, longestDistanceMiles = 0, longestDays = 0, tempInt = 0;
   double averageDistance = 0, averageDaysSpent = 0, numMiles = 0;

   //intro
   cout << "Welcome to the road trip analyzer program!" << endl
        << "Roadtrip origin, destination, waypoints, distance between waypoints in" << endl
        << "meters, and number of days spent at each waypoint will be read in from a" << endl
        << "file." << endl
        << "The program writes to an output file the distance in miles between each" << endl
        << "waypoint on the tripand statistics about the trip.Enjoy!" << endl
        << endl;

   //opens the input file
   inputFile.open(input);
   if (inputFile.is_open())
   {
      cout << "Successfully opened input file" << endl;
   }
   else
   {
      cout << "Failed to open input file" << endl;
      exit(-1);
   }
   //opens the output file
   outputFile.open(output);
   if (outputFile.is_open())
   {
      cout << "Successfully opened output file" << endl;
   }
   else
   {
      cout << "Failed to open output file" << endl;
      exit(-1);
   }
   cout << endl;
   cout << "Reading in road trip stop information from " << input << endl
        << endl;

   getline(inputFile, startingLocation);
   if (inputFile.good())
   {
      cout << "Roadtrip origin: " << startingLocation << endl;
      temp = startingLocation;
   }
   //starts the new line
   getline(inputFile, trashbin);
   while (!inputFile.eof())
   {
      inputFile >> numMiles;
      //converts the meters to miles
      numMiles = numMiles / 1609;

      //moves the end of the line to the trashbin so it is officially on the next line
      getline(inputFile, trashbin);
      //gets the new location of the waypoint
      getline(inputFile, location);
      //gets the amount of days spent at the waypoint from the file
      inputFile >> daysSpent;
      //cout << "Processing waypoint " << location << " (" << daysSpent << ") ..." << endl;
      if (numWaypoints > 0)
      {
         cout << "Processing waypoint " << temp << " (" << tempInt << " days) ..." << endl;
      }
      //outputs the string saying that they traveled from one location to another and the miles between
      outputFile << temp << " to " << location << ": " << numMiles << endl;
      //updates the longest distance between waypoints
      if (numMiles > longestDistanceMiles)
      {
         longestDisatanceName = location;
         longestDistanceMiles = numMiles;
         longestDistanceNameBefore = temp;
      }
      //updates the location where they spent the longest time at
      if (daysSpent > longestDays)
      {
         longestDaysName = location;
         longestDays = daysSpent;
      }
      //updates the total amount of miles
      totalMiles += numMiles;
      //updates total amount of days
      totalDays += daysSpent;
      //makes temp equal to the current location before moving on
      temp = location;
      //updates the amount of waypoints
      numWaypoints++;
      tempInt = daysSpent;
   }
   finalDestination = location;
   cout << "Roadtrip destination: " << finalDestination << endl;
   //Calculate averages
   averageDistance = static_cast<double>(totalMiles) / numWaypoints;
   averageDaysSpent = static_cast<double>(totalDays) / numWaypoints;

   cout << endl
        << "Writing stop stats to " << output << "..." << endl;
   //The huge output for the statistics
   outputFile << endl;
   outputFile << "**Road Trip Stats**" << endl;
   outputFile << "Number of waypoints on roadtrip: " << numWaypoints << endl;
   outputFile << "Number of days on roadtrip: " << totalDays << " days" << endl;
   outputFile << "Total miles traveled on roadtrip: " << totalMiles << " miles" << endl;
   outputFile << "Longest roadtrip distance between waypoints is " << longestDistanceNameBefore << " to " << longestDisatanceName << ": " << longestDistanceMiles << " miles" << endl;
   outputFile << "Longest roadtrip days at once is " << longestDaysName << ": " << longestDays << " days" << endl;
   outputFile << "Average roadtrip distance between stops is: " << averageDistance << " miles" << endl;
   outputFile << "Average roadtrip days spent at one waypoint: " << averageDaysSpent << " days" << endl;

   cout << "Closing files..." << endl;
   inputFile.close();
   outputFile.close();

   return 0;
}

/*
5 pts for displaying status messages to the console (line 53 and 71)
5 pts for opening and closing the input and output files (lines 31 and 40 [open] lines 115 and 116 [close])
10 pts for writing correct distances in miles between each consecutive road trip stop to the output file (line 74))
5 pts for writing the correct total number of waypoints on the road trip to the output file (8)
5 pts for writing the correct total number of days on the road trip to the output file (19)
5 pts for writing the correct total number of miles traveled on the road trip to the output file (276)
10 pts for writing the correct names of the two waypoints with the most distance between them and that distance in miles to the output file (Grand Canyon to NYC [153])
10 pts for writing the correct name of the waypoint with the longest stay and its number of days to the output file (NYC [5])
5 pts for writing the correct average miles between each stop to the output file (43.5)
5 pts for writing the correct average number of days spent at each waypoint to the output file (2.375)
5 pts for submitting your own input/output files (i.e., make your own input file!) (puryear_roadtrip.txt and puryear_roadtrip_stats.txt)
5 pts for adherence to proper programming style and comments established for the class (okay)
*/