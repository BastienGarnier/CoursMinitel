#include "list.h"

List list_new_empty() {
	List l;
	l.vn = malloc(sizeof(struct ListNode));
	l.vn->next = l.vn;
	l.vn->prev = l.vn;
	l.length = 0;
	return l;
}

void list_destroy(List l) {
	while (l.length != 0) {
		l = list_remove_tail(l);
	}
	free(l.vn);
}

bool list_is_empty(List l) {
	return (l.length == 0);
}

bool list_is_tail(List l, Place nd) {
	return nd == l.vn->prev;
}

bool list_is_head(List l, Place nd) {
	return nd == l.vn->next;
}

Place list_next(List l, Place nd) {
	return nd->next;
}

Place list_previous(List l, Place nd) {
	return nd->prev;
}

LIST_T list_get(List l, Place nd) {
	return nd->elt;
}

Place list_head(List l) {
	return l.vn->next;
}

Place list_tail(List l) {
	return l.vn->prev;
}

LIST_T list_head_get(List l) {
	return l.vn->next->elt;
}

LIST_T list_tail_get(List l) {
	return l.vn->prev->elt;
}

unsigned int list_length(List l) {
	return l.length;
}

List list_append_tail(List l, LIST_T x) {
	struct ListNode *new = malloc(sizeof(struct ListNode));

	new->next = l.vn;
	new->prev = l.vn->prev;
	l.vn->prev->next = new;
	l.vn->prev = new;
	new->elt = x;
	l.length++;
	return l;
}

List list_remove_tail(List l) {
	struct ListNode *to_del = l.vn->prev;
	l.vn->prev = to_del->prev;
	to_del->prev->next = l.vn;
	free(to_del);
	l.length--;
	return l;
}

List list_append_head(List l, LIST_T x) {
	struct ListNode *new = malloc(sizeof(struct ListNode));
	new->next = l.vn->next;
	new->prev = l.vn;
	l.vn->next->prev = new;
	l.vn->next = new;
	new->elt = x;
	l.length++;
	return l;
}

List list_remove_head(List l) {
	struct ListNode *to_del = l.vn->next;
	l.vn->next = to_del->next;
	to_del->next->prev = l.vn;
	free(to_del);
	l.length--;
	return l;
}

void list_display(List l, char *buffer) {
	buffer  += sprintf(buffer, "[%d]", list_length(l));
	Place iter = list_head(l);
	for (unsigned int i = 0; i < list_length(l); (++i, iter = list_next(l, iter))) {
		buffer += sprintf(buffer, "->%d", list_get(l, iter));
	}
}
