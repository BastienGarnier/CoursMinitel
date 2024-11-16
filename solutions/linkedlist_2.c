// stdio is not needed here
#include <stdlib.h> // just for EXIT_SUCCESS

#include "linkedlist.h"

int main() {

	struct LinkedList *l = linkedlist_new();

	linkedlist_push_on_head(l, 5);
	linkedlist_push_on_head(l, 4);
	linkedlist_push_on_queue(l, 6);

	linkedlist_display(l);

	return EXIT_SUCCESS;
}