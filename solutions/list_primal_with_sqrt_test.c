#include <stdio.h>
#include <stdlib.h>

#define N ...

char is_primal(unsigned int n) {
	char is_primal = n == 2 || (n > 2 && n % 2 != 0); // nécessaire
	for (int i = 3; i*i <= n && is_primal; i += 2) {
		is_primal = (n % i == 0) ? 0 : is_primal;
	}
	return is_primal;
}

int main() {
	unsigned int primes[N];
	unsigned int i = 3;
	unsigned int counter = 0;
	primes[0] = 2;
	printf("Listes des nombres premiers inferieurs a %u : %u;", N, primes[0]);
	while (i <= N) {
		if (is_primal(i)) {
			primes[++counter] = i;
			printf("%u;", primes[counter]);
		}
		i += 2;
	}
	printf("\n");

	return EXIT_SUCCESS;
}