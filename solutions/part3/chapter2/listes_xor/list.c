#include "list.h"

List list_new_empty() {
	List l;
	l.length = 0;
	l.head = l.tail = NULL;
	return l;
}

void list_destroy(List l) {
	while (l.length != 0) {
		l = list_remove_tail(l);
	}
}

bool list_is_empty(List l) {
	return (l.length == 0);
}

bool list_is_tail(List l, Place nd) {
	return nd == l.tail;
}

bool list_is_head(List l, Place nd) {
	return nd == l.head;
}

LIST_T list_get(List l, Place nd) {
	return nd->elt;
}

Place list_head(List l) {
	return l.head;
}

Place list_tail(List l) {
	return l.tail;
}

LIST_T list_head_get(List l) {
	return list_get(l, list_head(l));
}

LIST_T list_tail_get(List l) {
	return list_get(l, list_tail(l));
}

unsigned int list_length(List l) {
	return l.length;
}

List list_append_tail(List l, LIST_T x) {
	struct ListNode *new = malloc(sizeof(struct ListNode));
	if (l.tail != NULL) {
		new->pn = l.tail;
		l.tail->pn = (struct ListNode *)((uint64_t)(l.tail->pn) ^ (uint64_t)new);
	} else {
		new->pn = NULL;
		l.head = new;
	}
	l.tail = new;
	new->elt = x;
	l.length++;
	return l;
}

List list_remove_tail(List l) {
	struct ListNode *to_del = l.tail;
	if (l.length == 1) {
		l.head = l.tail = NULL;
	} else {
		struct ListNode *first = to_del->pn;
		first->pn = (struct ListNode *)((uint64_t)(first->pn) ^ (uint64_t)to_del);
		l.tail = first;
	}
	free(to_del);
	l.length--;
	return l;
}

List list_append_head(List l, LIST_T x) {
	struct ListNode *new = malloc(sizeof(struct ListNode));
	if (l.length != 0) {
		new->pn = l.head;
		l.head->pn = (struct ListNode *)((uint64_t)(l.head->pn) ^ (uint64_t)new);
	} else {
		new->pn = NULL;
		l.tail = new;
	}
	new->elt = x;
	l.head = new;
	l.length++;
	return l;
}

List list_remove_head(List l) {
	struct ListNode *to_del = l.head;
	if (l.length == 1) {
		l.head = l.tail = NULL;
	} else {
		struct ListNode *first = to_del->pn;
		first->pn = (struct ListNode *)((uint64_t)(first->pn) ^ (uint64_t)to_del);
		l.head = first;
	}
	free(to_del);
	l.length--;
	return l;
}

List list_reverse(List l) {
	struct ListNode *tmp = l.head;
	l.head = l.tail;
	l.tail = tmp;
	return l;
}

void list_display(List l, char *buffer) {
	buffer  += sprintf(buffer, "[%d]", list_length(l));
	struct ListNode *nd = list_head(l);
	if (nd == NULL) {
		return;
	}
	struct ListNode *t0 = NULL;
	struct ListNode *t1 = NULL;
	while (nd != NULL) {
		buffer += sprintf(buffer, "->%d", list_get(l, nd));
		t1 = nd;
		nd = (struct ListNode *)((uint64_t)(nd->pn) ^ (uint64_t)t0);;
		t0 = t1;
	}
}
