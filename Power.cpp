#include <stdio.h>
#include <time.h>

// 반복적인 거듭제곱
double iterationPower(double x, int n) {
	long double result = 1;

	for (int i = 0; i < n; i++) {
		result *= x;
	}

	return result;
}

// 순환적인 거듭제곱
double recursionPower(double x, int n) {
	if (n == 0) {
		return 1;
	}
	else if (n % 2 == 0) {
		return recursionPower(x * x, n / 2);
	}
	else {
		return x * recursionPower(x * x, (n - 1) / 2);
	}
}

int main() {
	clock_t start;
	float iterationTime, recursionTime;
	double x = 2;
	int n = 1000;

	start = clock();
	for (int i = 0; i < 100000; i++) {
		iterationPower(x, n);
	}
	iterationTime = (float)(clock() - start) / CLOCKS_PER_SEC;
	
	start = clock();
	for (int i = 0; i < 100000; i++) {
		recursionPower(x, n);
	}
	recursionTime = (float)(clock() - start) / CLOCKS_PER_SEC;

	printf("반복: %f\n", iterationTime);
	printf("순환: %f", recursionTime);

	return 0;
}