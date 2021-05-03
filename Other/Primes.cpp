#include <iostream>

using namespace std;

int isPrime(int i)
{
   int j;
   for (j = 3; j <= i / 2; j += 2)
   {
      if (i % j == 0)
      {
         return false;
      }
   }
   return true;
}
int main()
{
   int userNum;
   int nums = 0;
   int ver;
   cout << "Version 1 or Version 2?" << endl
        << "Version 1 is calculating and showing all of the numbers where version two shows you a specific number" << endl;
   cin >> ver;
   if (ver == 1)
   {
      cout << "How many numbers?" << endl;
      cin >> userNum;
      if (userNum < 1)
      {
         cout << "bruh..." << endl;
      }
      else
      {
         cout << endl;
         int i = 3;
         cout << 2 << endl;
         while (nums < userNum - 1)
         {
            if (isPrime(i))
            {
               cout << i << endl;
               nums++;
            }
            i += 2;
         }
      }
   }
   if (ver == 2)
   {
      cout << "Which prime number? " << endl
           << "eg. P(1) = 2, P(2) = 3, P(3) = 5..." << endl;
      cin >> userNum;
      if (userNum < 1)
      {
         cout << "bruh..." << endl;
      }
      else
      {
         cout << endl;
         int i = 3;
         while (nums < userNum - 1)
         {
            if (isPrime(i))
            {
               if (nums == userNum - 2)
               {
                  cout << "P(" << userNum << ") = " << i << endl;
               }
               nums++;
            }
            i += 2;
         }
      }
   }
   return 0;
}
