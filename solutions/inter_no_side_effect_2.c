#include <stdio.h>
#include <stdlib.h>

int main() {
	int a = ...;
	int b = ...;

	a = a ^ b;
	b = a ^ b;
	a = a ^ b;

	return EXIT_SUCCESS;
}