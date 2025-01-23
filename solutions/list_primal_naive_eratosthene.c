#include <stdio.h>
#include <stdlib.h>

#define N ...

int main() { 
	unsigned int primes[N];
	unsigned int counter = 0;
	unsigned int i = 3;
	primes[0] = 2;
	printf("Listes des nombres premiers inferieurs a %u : %u;", N, primes[0]);
	while (i <= N) {
		char is_primal = 1; // premier par défaut
		for (unsigned int k = 0; k <= counter && is_primal; k++) {
			is_primal = (i % primes[k] == 0 ? 0 : is_primal);
		}
		if (is_primal) {
			primes[++counter] = i;
			printf("%u;", primes[counter]);
		}
		i += 2;
	}

	printf("\n");

	return EXIT_SUCCESS;
}