#include <stdio.h>
#include <stdlib.h>

double** matrix_new(unsigned int n, unsigned int m) {
	double** mat = malloc(n * sizeof(double*));
	for (unsigned int i = 0; i < n; i++) {
		mat[i] = malloc(m * sizeof(double));
	}
	return mat;
}

void matrix_destroy(double** m, unsigned int n) {
	for (unsigned int i = 0; i < n; i++) {
		free(m[i]);
	}
	free(m);
}

void matrix_display(double** mat, unsigned int n, unsigned int m) {
	for (unsigned int i = 0; i < n; i++) {
		for (unsigned int j = 0; j < m; j++) {
			printf("|%.2lf|", mat[i][j]);
		}
		printf("\n");
	}
}

double** matrix_mul(double** a, double** b, unsigned n, unsigned m, unsigned o) {
	double** c = matrix_new(n, o);
	for (unsigned int i = 0; i < n; i++) {
		for (unsigned int j = 0; j < o; j++) {
			double x = 0;
			for (unsigned int k = 0; k < m; k++) {
				x += a[i][k]*b[k][j];
			}
			c[i][j] = x;
		}
	}
	return c;
}
