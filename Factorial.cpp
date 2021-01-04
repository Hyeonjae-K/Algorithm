#include <stdio.h>

// �ݺ����� ���丮��
long long int iterationFactorial(int n) {
	long long int result = 1;

	for (int i = n; i > 0; i--) {
		result *= i;
	}

	return result;
}

// ��ȯ���� ���丮��
long long int recursionFactorial(int n) {
	if (n == 1) {
		return 1;
	}
	else {
		return n * recursionFactorial(n - 1);
	}
}

int main() {
	int n = 10;

	printf("%lld\n", iterationFactorial(n));
	printf("%lld\n", recursionFactorial(n));

	return 0;
}