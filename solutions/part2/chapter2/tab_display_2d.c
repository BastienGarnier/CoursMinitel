#include <stdio.h>
#include <stdlib.h>

#define N 10
#define M 20

int main() {
	int array[N][M];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("|%d|", array[i][j]);
		}
		printf("\n");
	}

	return EXIT_SUCCESS;
}