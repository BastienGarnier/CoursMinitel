#include <stdio.h>
#include <stdlib.h>

int main() {
	int x = -5; // valeur quelconque positive ou négative 
	unsigned int abs_x = x;
	unsigned int positive = (abs_x >> 31) - 1; // -1 si positif, 0 si négative
	abs_x = ((~positive) & (-x)) | (positive & x);
	printf("|%d| = %u", x, abs_x);
	return EXIT_SUCCESS;
}