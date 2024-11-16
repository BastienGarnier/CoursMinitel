#include <stdio.h>
#include <stdlib.h>

int main() {
	int x = -5; // any positive or negative value
	unsigned int abs_x = x;
	unsigned int positive = (abs_x >> 31) - 1; // -1 if positive, 0 if negative
	abs_x = ((~positive) & (-x)) | (positive & x);
	printf("|%d| = %u", x, abs_x);
	return EXIT_SUCCESS;
}