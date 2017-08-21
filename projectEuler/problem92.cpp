#include <iostream>
#include <time.h>
#include <vector>
using namespace std;


//Can use a combinatorics method or
//just this solution

int sumOfDigitsSquared(long num) {
	if (num == 0) {
		return 0;
	}
	int digit = num % 10;
	return digit * digit + sumOfDigitsSquared(num / 10);
}

int main() {

clock_t time = clock();

const int bound = (9*9)*7 + 1; //9 * 9 = max square, 7 = max length of digits
const int MAX = 10000000;
int map[bound] = {0};
int count = 0;

for (long i = 1; i < MAX; i++) {
	int currNumber = sumOfDigitsSquared(i);
	int firstNumber = currNumber;
	for (;;) {
		if (currNumber == 1) {
			map[firstNumber] = 1;
			break;
			
		}
		else if (currNumber == 89) {
			map[firstNumber] = 2;
			count++;
			break;
		}
		else if (map[currNumber] == 2) {
			count++;
			break;
		}
		else if (map[currNumber] == 1) {
			break;
		}
		currNumber = sumOfDigitsSquared(currNumber);
	}
}

cout << count << endl;
cout << "Time: " << (clock() - time) / (double) CLOCKS_PER_SEC << endl;

}