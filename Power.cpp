#include <stdio.h>

// �ݺ����� �ŵ�����
double iterationPower(double x, int n) {
	long double result = 1;

	for (int i = 0; i < n; i++) {
		result *= x;
	}

	return result;
}

// ��ȯ���� �ŵ�����
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
	double x = 1.12345;
	int n = 100;

	printf("%lf\n", iterationPower(x, n));
	printf("%lf\n", recursionPower(x, n));

	return 0;
}