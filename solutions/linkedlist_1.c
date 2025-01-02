#include <stdio.h>
#include <stdlib.h>

struct Node {
	struct Node* next;
	struct Node* previous;
	int value;
};

struct Node* node_new(int value) {
	struct Node* nd = malloc(sizeof(struct Node));
	nd->next = NULL;
	nd->previous = NULL;
	nd->value = value;
	return nd;
}

struct LinkedList {
	struct Node *head;
	struct Node *tail;
	unsigned int length;
};

struct LinkedList* linkedlist_new() {
	struct LinkedList* lst = malloc(sizeof(struct LinkedList));
	lst->length = 0;
	lst->head = NULL;
	lst->tail = NULL;
	return lst;
}

char linkedlist_is_empty(struct LinkedList* l) {
	return l->length == 0;
}

void linkedlist_push_on_head(struct LinkedList *l, int value) {
	struct Node *nd = node_new(value);
	if (linkedlist_is_empty(l)) {
		l->head = l->tail = nd;
	} else {
		l->head->previous = nd;
		nd->next = l->head;
		l->head = nd;
	}
	l->length++;
}

void linkedlist_push_on_tail(struct LinkedList *l, int value) {
	struct Node *nd = node_new(value);
	if (linkedlist_is_empty(l)) {
		l->head = l->tail = nd;
	} else {
		l->tail->next = nd;
		nd->previous = l->tail;
		l->tail = nd;
	}
	l->length++;
}

int linkedlist_pop_from_head(struct LinkedList *l) {
	int to_return = -1;
	if (!linkedlist_is_empty(l)) {
		struct Node *to_delete = l->head;
		l->head = to_delete->next;
		if (l->head != NULL) { // if l->length == 1
			l->head->previous = NULL;
		}
		to_return = to_delete->value;
		free(to_delete);
		l->length--;
	} else {
		fprintf(stderr, "Erreur : tentative de suppression d'un element d'une liste vide.\n");
	}
	return to_return;
}

int linkedlist_pop_from_tail(struct LinkedList *l) {
	int to_return = -1;
	if (!linkedlist_is_empty(l)) {
		struct Node *to_delete = l->tail;
		l->tail = to_delete->previous;
		if (l->tail != NULL) { // if l->length == 1
			l->tail->next = NULL;
		}
		to_return = to_delete->value;
		free(to_delete);
		l->length--;
	} else {
		fprintf(stderr, "Erreur : tentative de suppression d'un element d'une liste vide.\n");
	}
	return to_return;
}

void linkedlist_display(struct LinkedList *l) {
	struct Node *tmp = l->head;
	while (tmp != NULL) {
		printf("->%d", tmp->value);
		tmp = tmp->next;
	}
	printf("\n");
}

int main() {

	struct LinkedList *l = linkedlist_new();

	linkedlist_push_on_head(l, 5);
	linkedlist_push_on_head(l, 4);
	linkedlist_push_on_tail(l, 6);

	linkedlist_display(l);

	return EXIT_SUCCESS;
}