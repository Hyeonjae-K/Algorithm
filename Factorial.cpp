#include <stdio.h>

long long int iterationFactorial(int n) {
	long long int result = 1;

	for (int i = n; i > 0; i--) {
		result *= i;
	}

	return result;
}

long long int recursionFactorial(int n) {
	if (n == 1) {
		return 1;
	}
	else {
		return n * recursionFactorial(n - 1);
	}
}

int main() {
	printf("%lld\n", iterationFactorial(20));
	printf("%lld\n", recursionFactorial(20));

	return 0;
}