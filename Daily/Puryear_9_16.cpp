
#include <iostream>

using namespace std;

int main()
{
   cout << "Please enter 2 numbers. Have the first number be bigger than the second\nex. \"10 5\"" << endl;
   /*
	Gets the two numbers 
	*/
   int num1;
   int num2;
   cin >> num1;
   cin >> num2;
   cout << num1 << endl;
   cout << num2 << endl;
   /*
		sum
			*/
   int sum = num1 + num2;
   cout << num1 << " + " << num2 << " = " << sum << endl;
   /*
		diff
			*/
   int diff = num1 - num2;
   cout << num1 << " - " << num2 << " = " << diff << endl;
   /*	
		product
			*/
   int product = num1 * num2;
   cout << num1 << " * " << num2 << " = " << product << endl;
   /*
		div
			*/
   int div = num1 / num2;
   cout << num1 << " / " << num2 << " = " << div << endl;
   /*
		remainder
			*/
   int remainder = num1 % num2;
   cout << num1 << " % " << num2 << " = " << remainder << endl;

   return 0;
}
