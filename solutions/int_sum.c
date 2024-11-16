#include <stdio.h>
#include <stdlib.h>

#define N 10

int main() {
	int somme = 0;
	int x;
	for (int i = 0; i < N; i++) {
		printf("Entrer l'entier %d : ", i + 1);
		if (scanf("%d", &x) == 1) {
			somme += x;
		} else {
			fprintf(stderr, "Il fallait entrer un entier !!!");
			return EXIT_FAILURE;
		}
	}
	printf("Somme : %d\n", somme);
	return EXIT_SUCCESS;
}