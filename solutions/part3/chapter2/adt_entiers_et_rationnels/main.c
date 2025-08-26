#include <stdio.h>
#include <stdlib.h>

#include "integer.h"

char buffer[8192];

Integer factorial(Integer n) {
	Integer tmp = integer_copy(n);
	Integer un = integer_new_b256(2, (uint8_t[]){0, 1}, POSITIVE);
	Integer x = integer_copy(un);
	while (!integer_is_zero(tmp)) {
		integer_mulm(&x, tmp);
		integer_subm(&tmp, un);
	}
	integer_destroy(tmp);
	integer_destroy(un);
	return x;
}

int main() {
	Integer cent = integer_new("100");
	Integer n = integer_new("-647");
	Integer m = integer_new("256");

	printf("n = %s\n", (integer_display(n, buffer), buffer));
	printf("m = %s\n", (integer_display(m, buffer), buffer));

	Integer fn = factorial(cent);
	printf("100! = %s\n", (integer_display(fn, buffer), buffer));

	integer_destroy(cent);
	integer_destroy(fn);
	integer_destroy(n);
	integer_destroy(m);

	return EXIT_SUCCESS;
}