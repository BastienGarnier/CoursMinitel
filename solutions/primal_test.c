#include <stdio.h>
#include <stdlib.h>

#define N ...

int main() {
	char is_primal = N == 2 || (N > 2 && N % 2 != 0); // nécessaire
	for (int i = 3; i < N-1 && is_primal; i += 2) {
		is_primal = (N % i == 0) ? 0 : is_primal;
	}

	if (is_primal) {
		printf("Premier !\n");
	} else {
		printf("Pas premier...\n");
	}

	return EXIT_SUCCESS;
}