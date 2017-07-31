#include <iostream>
#include <math.h>
#include <time.h>
using namespace std;

//The normal algorithm for modular exponentaiton goes beyond the max limit of 
//unsigned long long, so we must perform a much much slower calculation of O(n)
//rather than O(logn). This is very sad. The way to fix this would to make our
//own implementaiton of BigInteger class, something that will greatly improve
//the time of execution for this program and help out in many other problems
//on project euler
long long modularExponentation(long long base, long power, long long modular) {
	long long result = 1;
	while (power > 0) {
		result = (result * base) % modular;
		power--;
	}
	return result;
}

int main() {

clock_t time = clock();

long long modular = pow(10, 10);

cout << (modularExponentation(2, 7830457, modular) * 28433 + 1) % modular << endl;
cout << (clock() - time) / (double) CLOCKS_PER_SEC << endl;
}
