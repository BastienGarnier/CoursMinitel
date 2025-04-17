#include <stdio.h>
#include <stdlib.h>

int main() {
	int a = 57;
	int r = (a << 4) - (a << 1);
	printf("57x14 = %d", r);
	return EXIT_SUCCESS;
}