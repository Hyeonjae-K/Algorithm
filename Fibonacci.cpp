#include <stdio.h>
#include <time.h>

// 반복적인 피보나치 계산
int iterationFibonacci(int n) {
	if (n < 2) {
		return n;
	}
	else {
		int tmp, current = 1, last = 0;
		for (int i = 0; i <= n - 2; i++) {
			tmp = current;
			current = tmp + last;
			last = tmp;
		}

		return current;
	}
}

// 순환적인 피보나치 계산
int recursionFibonacci(int n) {
	if (n == 0) {
		return 0;
	}
	else if (n == 1) {
		return 1;
	}
	else {
		return recursionFibonacci(n - 2) + recursionFibonacci(n - 1);
	}
}

int main() {
	clock_t start;
	float iterationTime, recursionTime;
	int n = 10;

	start = clock();
	for (int i = 0; i < 1000000; i++) {
		iterationFibonacci(n);
	}
	iterationTime = (float)(clock() - start) / CLOCKS_PER_SEC;

	start = clock();
	for (int i = 0; i < 1000000; i++) {
		recursionFibonacci(n);
	}
	recursionTime = (float)(clock() - start) / CLOCKS_PER_SEC;

	printf("반복: %f\n", iterationTime);
	printf("순환: %f\n", recursionTime);

	return 0;
}