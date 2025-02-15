#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N ...

int main() {
	srand(time(NULL));

	unsigned int mystery = rand() % N;
	unsigned int guess = -1;
	unsigned int tentatives = 0;
	printf("Un nombre mystere a ete tire entre 0 et %u inclu !\n", N-1);
	for (; guess != mystery; ++tentatives) {
		printf("Quel est le nombre mystere ?\n> ");
		fscanf(stdin, "%u", &guess); // strictement équivalent à scanf("%u", &guess);
		if (guess > mystery) {
			printf("Le nombre mystere est plus petit\n");
		}
		if (guess < mystery) {
			printf("Le nombre mystere est plus grand\n");
		}
	}
	printf("Youpiii tu as trouve le nombre mystere en %u tentatives !\n", tentatives);
	return EXIT_SUCCESS;
}