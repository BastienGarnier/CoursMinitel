// stdio est non nécessaire ici
#include <stdlib.h> // juste pour EXIT_SUCCESS

#include "linkedlist.h"

int main() {

	struct LinkedList *l = linkedlist_new();

	linkedlist_push_on_head(l, 5);
	linkedlist_push_on_head(l, 4);
	linkedlist_push_on_tail(l, 6);

	linkedlist_display(l);

	return EXIT_SUCCESS;
}