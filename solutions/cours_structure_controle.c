#include <stdio.h>
#include <stdlib.h>

#define N ...

int main() {
	int u = 3;
	unsigned int n = 0;
	while (n < N) {
		u = 3*u*u - 5*u + 2;
		n++;
		printf("u(%u) = %d\n", n, u);
	}
	return EXIT_SUCCESS;
}