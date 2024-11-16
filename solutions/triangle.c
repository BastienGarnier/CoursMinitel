#include <stdio.h>
#include <stdlib.h>

#define N_LINES 5 // we assum it's always odd

int min(int a, int b) {
	return (a > b) ? b : a;
}

void print_array(int** triangle, unsigned int n_lines) {
	for (int i = 0; i < n_lines; i++) {
		for (int j = 0; j < (1 + min(N_LINES - i - 1, i)); j++) {
			printf("|%d|", triangle[i][j]);
		}
		printf("\n");
	}
}

int main() {
	int** triangle = (int**)(malloc(sizeof(int*) * N_LINES));
	for (int i = 0; i < N_LINES; i++) {
		triangle[i] = (int*)(malloc(sizeof(int) * (1 + min(N_LINES - i - 1, i))));
	}

	int cnt = 0;
	for (int i = 0; i < N_LINES; i++) {
		for (int j = 0; j <	(1 + min(N_LINES - i - 1, i)); j++) {
			triangle[i][j] = ++cnt;
		}
	}

	print_array(triangle, N_LINES);
	return EXIT_SUCCESS;
}