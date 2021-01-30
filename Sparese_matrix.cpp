#include <stdio.h>
#include <stdlib.h>
#define ROWS 3
#define COLS 3
#define MAX_TERMS 10

// Èñ¼ÒÇà·Ä µ¡¼À1 ÇÔ¼ö
void spares_matrix_add1(int A[][COLS], int B[][COLS], int C[][COLS]) {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			C[i][j] = A[i][j] + B[i][j];
		}
	}
}

// Èñ¼ÒÇà·Ä Ãâ·Â1
void print_spares_matrix1(int A[][COLS]) {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
}

// Èñ¼ÒÇà·Ä µ¡¼À2 ±¸Á¶Ã¼
typedef struct {
	int row, col, val;
} element;
typedef struct {
	element data[MAX_TERMS];
	int rows, cols, terms;
} SparesMatrix;

//Èñ¼ÒÇà·Ä µ¡¼À2 ÇÔ¼ö
SparesMatrix spares_matrix_add2(SparesMatrix A, SparesMatrix B) {
	SparesMatrix C;
	int ca, cb, cc;
	ca = 0;
	cb = 0;
	cc = 0;

	if (A.rows != B.rows || A.cols != B.cols) {
		printf("Èñ¼ÒÇà·Ä Å©±â ¿¡·¯\n");
		exit(1);
	}
	C.rows = A.rows;
	C.cols = A.cols;
	C.terms = A.terms;

	while (ca < A.terms && cb < B.terms) {
		int inda = A.data[ca].row * A.cols + A.data[ca].col;
		int indb = B.data[cb].row * B.cols + B.data[cb].col;
		if (inda < indb) {
			C.data[cc++] = A.data[ca++];
		}
		else if (inda == indb) {
			if (A.data[ca].val + B.data[cb].val != 0) {
				C.data[cc].row = A.data[ca].row;
				C.data[cc].col = A.data[ca].col;
				C.data[cc++].val = A.data[ca++].val + B.data[cb++].val;
			}
			else {
				ca++;
				cb++;
			}
		}
		else {
			C.data[cc++] = B.data[cb++];
		}
	}

	for (; ca < A.terms;) {
		C.data[cc++] = A.data[ca++];
	}
	for (; cb < B.terms;) {
		C.data[cc++] = B.data[cb++];
	}
	C.terms = cc;

	return C;
}

// Èñ¼ÒÇà·Ä Ãâ·Â2
void print_spares_matrix2(SparesMatrix A) {
	int idx = 0;
	for (int i = 0; i < A.rows; i++) {
		for (int j = 0; j < A.cols; j++) {
			if (A.data[idx].row == i && A.data[idx].col == j) {
				printf("%d ", A.data[idx++].val);
			}
			else {
				printf("0 ");
			}
		}
		printf("\n");
	}
}

int main() {
	int A1[ROWS][COLS] = { {2, 3, 0}, {8, 9, 1}, {7, 0, 5} };
	int B1[ROWS][COLS] = { {1, 0, 0}, {1, 0, 0}, {1, 0, 0} };
	int C1[ROWS][COLS];
	spares_matrix_add1(A1, B1, C1);
	print_spares_matrix1(C1);

	SparesMatrix A2 = { {{1, 1, 5}, {2, 2, 9}}, 3, 3, 2 };
	SparesMatrix B2 = { {{0, 0, 5}, {2, 2, 9}}, 3, 3, 2 };
	SparesMatrix C2 = spares_matrix_add2(A2, B2);
	print_spares_matrix2(C2);

	return 0;
}