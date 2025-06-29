#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main() {
	List l = list_new_empty();

	for (unsigned int i = 0; i < 10; i++) {
		l = list_append_tail(l, i*i);
	}
	char buffer[100];
	printf("%s\n", (list_display(l, buffer), buffer));

	list_destroy(l);
	return EXIT_SUCCESS;
}