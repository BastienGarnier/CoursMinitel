#include <stdio.h>
#include <stdlib.h>
#include "list.h"

List list_sorted_merge(List l1, List l2) { // on suppose l1 et l2 triées
	List l = list_new_empty();

	Place iter1 = list_head(l1);
	Place iter2 = list_head(l2);

	unsigned int i = 0;
	unsigned int j = 0;

	if (!list_is_empty(l1)) {
		l = list_append_tail(l, list_head_get(l1));
		iter1 = list_next(l1, iter1);
		i++;
	} else if (!list_is_empty(l2)) {
		l = list_append_tail(l, list_head_get(l2));
		iter2 = list_next(l2, iter2);
		j++;
	} else {
		return l;
	}

	while (i < list_length(l1) || j < list_length(l2)) {
		int x;
		int v1 = list_get(l1, iter1), v2 = list_get(l2, iter2);
		if (i >= list_length(l1)) {
			x = v2;
			iter2 = list_next(l2, iter2);
			j++;
		} else if (j >= list_length(l2)) {
			x = v1;
			iter1 = list_next(l1, iter1);
			i++;
		} else {
			if (v1 > v2) {
				x = v2;
				iter2 = list_next(l2, iter2);
				j++;
			} else {
				x = v1;
				iter1 = list_next(l1, iter1);
				i++;
			}
		}
		
		if (x != list_tail_get(l)) {
			l = list_append_tail(l, x);
		}
	}
	return l;
}

int main() {
	char buffer[1024];

	List t1 = list_new_empty(), t2 = list_new_empty();

	for (unsigned int i = 0; i <10; i++) {
		t1 = list_append_tail(t1, 2*i);
		t2 = list_append_tail(t2, 3*i);
	}

	List merged = list_sorted_merge(t1, t2);
	printf("%s\n", (list_display(t1, buffer), buffer));
	printf("%s\n", (list_display(t2, buffer), buffer));
	printf("%s\n", (list_display(merged, buffer), buffer));

	return EXIT_SUCCESS;
}