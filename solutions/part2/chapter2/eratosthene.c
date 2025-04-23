#include <stdio.h>
#include <stdlib.h>

#define N ...

int ceiling_divide(int a, int b) {
	return a/b + (a % b != 0);
}

int main() {
	unsigned int nb_primes = 0;
	unsigned int P[N];
	P[0] = 0;
	P[1] = 0;
	for (unsigned int i = 2; i < N; i++) {
		P[i] = 1;
	}
	unsigned int p = 2;
	while (p*p <= N) {
		for (unsigned int f = p; f < ceiling_divide(N, p); f++) {
			P[p*f] = 0;
		}
		do {
			p++;
		} while (p < N && !P[p]);
	}
	for (unsigned int i = 0; i < N; i++) {
		nb_primes += P[i];
	}
	printf("Nb primes : %u\n", nb_primes);
	return EXIT_SUCCESS;
}