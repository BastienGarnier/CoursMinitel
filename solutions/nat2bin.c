#include <stdlib.h>
#include <stdio.h>

char* bin_from_nat(int n) {
	char* b = (char*)malloc(8*sizeof(int)*sizeof(char)); // 8 car sizeof(int) est en octets

	for (unsigned int i = 0; n > 0; i++) {
		b[i] = n%2;
		n /= 2;
	}
	return b;
}

void bin_display(char* b) {
	for (unsigned int i = 0; i < 8*sizeof(int); i++) {
		printf("%d", b[8*sizeof(int) - i - 1]);
	}
	printf("\n");
}

int main() {
	char* tab = bin_from_nat(5);
	bin_display(tab);
	free(tab);
	return EXIT_SUCCESS;
}