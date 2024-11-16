#include <stdio.h>
#include <stdlib.h>

int main() {
	unsigned int n;
	printf("Saisir un nombre entier : ");
	scanf("%u", &n);

	char is_primal = n == 2 || (n > 2 && n % 2 != 0); // necessary
	for (int i = 3; i < n-1 && is_primal; i += 2) {
		is_primal = (n % i == 0) ? 0 : is_primal;
	}

	if (is_primal) {
		printf("Premier !\n");
	} else {
		printf("Pas premier...\n");
	}

	return EXIT_SUCCESS;
}