#include <stdio.h>
#include <stdlib.h>

int main() {
	int a = ...; // any value
	int b = ...; // any value

	// the swap :
	a = a + b;
	b = a - b; // b = a + b - b = a
	a = a - b; // a = a + b - a = b

	return EXIT_SUCCESS;
}