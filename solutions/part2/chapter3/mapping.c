void array_map(int array[], unsigned int length, void (*const f)(int*)) {
	for (unsigned int i = 0; i < length; i++) {
		f(&array[i]);
	}
}

void linkedlist_map(struct LinkedList *l, void (*const f)(int*)) {
	if (linkedlist_error_access(l)) {return;}
	struct Node *tmp = l->head;
	while (tmp != NULL) {
		f(tmp->value);
		tmp = tmp->next;
	}
}