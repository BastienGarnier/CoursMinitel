#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

struct Matrix {
	double** mat;
	unsigned int n;
	unsigned int m;
};

struct Matrix matrix_new(unsigned int n, unsigned int m);
void matrix_destroy(struct Matrix m);
void matrix_display(struct Matrix m);
struct Matrix matrix_mul(struct Matrix a, struct Matrix b);

#endif