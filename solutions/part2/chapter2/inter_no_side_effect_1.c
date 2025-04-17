#include <stdio.h>
#include <stdlib.h>

int main() {
	int a = ...; // valeur quelconque
	int b = ...; // valeur quelconque

	// l'échange :
	a = a + b;
	b = a - b; // b = a + b - b = a
	a = a - b; // a = a + b - a = b

	return EXIT_SUCCESS;
}