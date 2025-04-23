void array_map(int array[], unsigned int length, void (*const f)(int*)) {
	for (unsigned int i = 0; i < length; i++) {
		f(&array[i]);
	}
}

void linkedlist_map(struct LinkedList *l, void (*const f)(int*)) {
	if (linkedlist_error_access(l)) {return;}
	for (struct Node *tmp = l->head; tmp != NULL; tmp = tmp->next) {
		f(tmp->value);
	}
}