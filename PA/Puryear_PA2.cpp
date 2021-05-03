#include <cmath>
#include <iostream>
#include <string>

using namespace std;

int main()
{
   string q1;
   string q2;
   string q7;
   int q3;
   int q4;
   int answer5;
   int answer6;
   int q8;
   int answer9;
   int answer10;
   int yes = 0;
   bool q6 = true;
   bool q9 = true;
   bool q5 = false;
   bool q10 = true;

   cout << "Welcome to the \"Are you a fan of the Middle Earth Universe?\" Quiz." << endl;
   //Q1
   cout << "Question #1:\nWhat is Sams relationship with Frodo?" << endl;
   cout << "a. Friends since birth\n"
           "b. Met at Bilbo's 105th birthday, many years before the LoTR\n"
           "c. Sam is Frodo's gardener\n"
           "d. They never met till the start of LoTR\n"
           "e. They are cousins"
        << endl;
   cout << "The answer is: ";
   cin >> q1;
   if (q1 == "c")
   {
      cout << "Amazing! Its weird to think that Sam is just Frodo's gardener." << endl
           << endl;
      yes++;
   }
   else
   {
      cout << "Sorry but the correct answer is c. Sam is Frodo's gardener" << endl
           << endl;
   }

   //Q2
   cout << "Question #2: In Tolkiens book The Simarilion, the first section is titled Ainulindale and it focuses on the\ncreation of the universe.\n"
           "how did they create the universe?"
        << endl;
   cout << "a. Singing\n"
           "b. Dancing\n"
           "c. Speaking\n"
           "d. Thinking it to be so\n"
           "e. Does not say"
        << endl;
   cout << "The answer is: ";
   cin >> q2;
   if (q2 == "a")
   {
      cout << "Awesome! I've always loved the idea of singing the universe into reality." << endl
           << endl;
      yes++;
   }
   else
   {
      cout << "Soryy but the correct answer is a. Singing." << endl
           << endl;
   }

   //Q3
   cout << "Question #3: What year of the third age did\nElrond, Galadriel, Gandalf, Frodo and Bilbo depart from the Grey Havens and go to the Undying Lands?" << endl;
   cout << "They left in the year: TA (Third Age) ";
   cin >> q3;

   if (q3 == 3021)
   {
      cout << "Correct!" << endl
           << endl;
      yes++;
   }
   else
   {
      cout << "Nope, they departed in the year TA 3021." << endl
           << endl;
   }
   //Q4
   cout << "Question #4: How old was Frodo when he left for the Grey Havens?" << endl;
   cout << "He was __ years old: ";
   cin >> q4;
   if (q4 == 53)
   {
      cout << "Perfect!" << endl
           << endl;
      yes++;
   }
   else
   {
      cout << "Sorry, but he was actually 53 years old" << endl
           << endl;
   }

   //Q5
   cout << "Question #5: True or false:\nThe reason evil exists in this universe is because one of the creators sang too fast." << endl;
   cout << "Enter a 0 for false and a 1 for true: ";

   cin >> answer5;
   if (static_cast<bool>(answer5) == q5)
   {
      cout << "Yep! The correct answer was that one of the creators purposfully sang out of tune. So cool" << endl
           << endl;
      yes++;
   }
   else
   {
      cout << "Nope, the correct answer is that one of them sang out of tune, they never said anything about tempo" << endl
           << endl;
   }

   //Q6
   cout << "Question #6: True or false: The dark lords real name is Melkor." << endl;
   cout << "Enter a 0 for false and a 1 for true: ";

   cin >> answer6;
   if (static_cast<bool>(answer6) == q6)
   {
      cout << "Yep!" << endl
           << endl;
      yes++;
   }
   else
   {
      cout << "Nope! Its true!" << endl
           << endl;
   }

   //Q7
   cout << "Question #7: What is the correct spelling of the characters last name\nthat the fellowship meets at the start of their journey. His first name was Tom." << endl;
   cout << "The characters name is Tom ";
   cin >> q7;
   if (q7 == "Bombadil")
   {
      cout << "Yep!" << endl
           << endl;
      yes++;
   }
   else
   {
      cout << "Nope. It is spelled Bombadil." << endl
           << endl;
   }

   //Q8
   cout << "Question #8: What year in the first age was Elrond of the House of Marach born?" << endl;
   cout << "Elrond was born: FA (First Age) ";
   cin >> q8;
   if (q8 == 532)
   {
      cout << "yep! wow you are good" << endl
           << endl;
      yes++;
   }
   else
   {
      cout << "Nope. The answer is FA 532." << endl
           << endl;
   }

   //Q9
   cout << "Question #9: True or false: Malgor is a son of F�anor." << endl;
   cout << "Enter a 0 for false and a 1 for true: ";

   cin >> answer9;
   if (static_cast<bool>(answer9) == q9)
   {
      cout << "Yep!" << endl
           << endl;
      yes++;
   }
   else
   {
      cout << "Nope! The answer is yes" << endl
           << endl;
   }
   //Q10
   cout << "Question #10: True or false: A nickname for Valmar was the City of Bells." << endl;
   cout << "Enter a 0 for false and a 1 for true: ";

   cin >> answer10;
   if (static_cast<bool>(answer10) == q10)
   {
      cout << "Yep!" << endl
           << endl;
      yes++;
   }
   else
   {
      cout << "Nope! The answer is yes." << endl
           << endl;
   }

   cout << "You got " << yes << " answer(s) correct!" << endl;
   return 0;
}

/*
	10 pts for at least 2 multiple choice questions
	10 pts for at least 2 numeric response questions
	10 pts for at least 2 Boolean questions
	10 pts for 4 additional questions (your choice on question type)
	10 pts for proper type casting and comparisons for True/False questions with the bool type
	5 points for numbering questions and stating the response format in your question prompts
	5 points for letting the user know if they are correct and for providing the correct answer
	when they are wrong
	10 points for displaying a message at the end of the quiz based on the number of correct
	responses using an if-else structure
	5 pts for adherence to proper programming style and comments established for the class
*/