#include <stdio.h>
#include <stdlib.h>

#include "integer.h"

char buffer[8192];

Integer aux(Integer n, Integer acc, Integer un) {
	Integer dix = integer_new("637");
	if (integer_is_zero(n)) {
		return acc;
	}
	integer_mulm(&acc, n);
	integer_usubml(&n, un);
	if (integer_ucmp(n, dix) >= 0) {
		printf("ACC = %s\n", (integer_display_b256(acc, buffer), buffer));
	}
	return aux(n, acc, un);
}

Integer factorial(Integer n) {
	Integer un = integer_new_b256(1, (uint8_t[]){1}, POSITIVE);
	Integer f = aux(n, integer_copy(un), un);
	integer_destroy(un);
	return f;
}

int main() {
	Integer un = integer_new_b256(1, (uint8_t[]){1}, POSITIVE);
	Integer dix = integer_new_b256(1, (uint8_t[]){10}, POSITIVE);

	Integer n = integer_new("-647");
	Integer m = integer_new("-256");

	printf("n = %s\n", (integer_display(n, buffer), buffer));
	printf("m = %s\n", (integer_display(m, buffer), buffer));
	printf("n = %s\n", (integer_display_b256(n, buffer), buffer));
	printf("m = %s\n", (integer_display_b256(m, buffer), buffer));
	switch (integer_cmp(n, m)) {
	case 0:
		printf("647 == -256\n");
		break;
	case 1:
		printf("647 > -256\n");
		break;
	case -1:
		printf("647 < -256\n");
		break;
	}
	
	integer_addm(&m, n);
	printf("647 + 256 = %s", (integer_display_b256(m, buffer), buffer));
	// Integer m = integer_new("646");

	// integer_mulm(&m, n);
	// printf("647 * 646 = %s\n", (integer_display_b256(m, buffer), buffer));

	// Integer fn = factorial(n);

	integer_destroy(n);
	integer_destroy(m);

	return EXIT_SUCCESS;
}