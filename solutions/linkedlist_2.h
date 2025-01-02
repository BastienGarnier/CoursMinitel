#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>

struct Node {
	struct Node* next;
	struct Node* previous;
	int value;
};

struct Node* node_new(int value);

struct LinkedList {
	struct Node *head;
	struct Node *tail;
	unsigned int length;
};

struct LinkedList* linkedlist_new();
char linkedlist_is_empty(struct LinkedList* l);
void linkedlist_push_on_head(struct LinkedList *l, int value);
void linkedlist_push_on_tail(struct LinkedList *l, int value);
int linkedlist_pop_from_head(struct LinkedList *l);
int linkedlist_pop_from_tail(struct LinkedList *l);
void linkedlist_display(struct LinkedList *l);

#endif