#include <stdio.h>
#include <stdlib.h>

double coords_to_point(float x, float y) {
	double p;
	float *ptr = (float *)&p;
	ptr[0] = x; // *ptr = x;
	ptr[1] = y; // *(ptr + 1) = y;
	return p;
}

double substract(double pA, double pB) {
	float *ptrA = (float *)&pA;
	float *ptrB = (float *)&pB;
	float x = ptrA[0] - ptrB[0]; // *ptrA - *ptrB
	float y = ptrA[1] - ptrB[1]; // *(ptrA + 1) - *(ptrB + 1)
	return coords_to_point(x, y);
}

float absolute(float x) {
	if (x < 0) {
		return -x;
	}
	return x;
}

float norme1(double p) {
	float *ptr = (float *)&p;
	return absolute(ptr[0]) + absolute(ptr[1]);
}

float distance(double pA, double pB) {
	return norme1(substract(pA, pB));
}

int main() {
	double pA = coords_to_point(3.0, 4.0);
	double pB = coords_to_point(-1.0, -1.0);
	printf("%f\n", distance(pA, pB)); // prints 9.000000
	return EXIT_SUCCESS;
}