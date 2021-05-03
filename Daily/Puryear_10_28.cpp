#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

int main()
{
	srand(time(NULL));

	int nums[10];
	for (int i = 0; i < 10; i++) {
		int randomNum = rand() % 10 + 1;
		nums[i] = randomNum;
	}
	for (int i = 0; i < 10; i++) {
		cout << "nums[" << i << "] = " << nums[i] << endl;
	}

	return 0;
} 