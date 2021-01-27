#define _CRT_SECURE_NO_WARNINGS
#define MAX_DEGREE 6
#define MAX(a, b) (a > b ? a : b)
#include <stdio.h>

typedef struct {
	int degree;
	float coef[MAX_DEGREE];
}polynomial;

polynomial add_poly1(polynomial A, polynomial B) {
	polynomial C;
	C.degree = MAX(A.degree, B.degree);
	
	for (int i = 0; i < C.degree + 1; i++) {
		if (A.degree > B.degree) {
			C.coef[i] = A.coef[i];
			A.degree--;
		}
		else if (A.degree < B.degree) {
			C.coef[i] = B.coef[i];
			B.degree--;
		}
		else {
			C.coef[i] = A.coef[i] + B.coef[i];
		}
	}

	return C;
}



int main() {
	polynomial A1 = { 5, {3, 6, 0, 0, 0, 10} };
	polynomial B1 = { 4, {7, 0, 5, 0, 1} };
	polynomial C1 = add_poly1(A1, B1);

	return 0;
}