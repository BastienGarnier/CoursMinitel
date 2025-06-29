#include "list.h"

List list_new_empty() {
	List l;
	l.buffer = malloc(sizeof(LIST_T));
	l.capacity = 1;
	l.head = 0;
	l.tail = 0;
	l.length = 0;
	return l;
}

void list_destroy(List l) {
	free(l.buffer);
}

bool list_is_empty(List l) {
	return (l.length == 0);
}

bool list_is_tail(List l, Place p) {
	return p == l.tail;
}

bool list_is_head(List l, Place p) {
	return p == l.head;
}

Place list_next(List l, Place p) {
	return (p + 1 > l.tail) ? l.head : p + 1;
}

Place list_previous(List l, Place p) {
	return (p < l.head + 1) ? l.tail : p - 1;
}

LIST_T list_get(List l, Place p) {
	return l.buffer[p];
}

Place list_head(List l) {
	return l.head;
}

Place list_tail(List l) {
	return l.tail;
}

LIST_T list_head_get(List l) {
	return l.buffer[l.head];
}

LIST_T list_tail_get(List l) {
	return l.buffer[l.tail];
}

unsigned int list_length(List l) {
	return l.length;
}

List list_append_tail(List l, LIST_T x) {
	l.length++;
	if (l.length > l.capacity) {
		int* new_buffer = malloc(sizeof(LIST_T) * (l.capacity << 1)); // x << 1 = x * 2
		for (unsigned int i = 0; i < l.capacity; i++) {
			new_buffer[i] = l.buffer[i];
		}
		l.capacity = l.capacity << 1;
	}
	l.tail = (l.tail + 1) % l.capacity;
	l.buffer[l.tail] = x;
	return l;
}

List list_remove_tail(List l) {
	l.length--;
	l.tail = (l.tail - 1) % l.capacity;
	return l;
}

List list_append_head(List l, LIST_T x) {
	l.length++;
	if (l.length > l.capacity) {
		int* new_buffer = malloc(sizeof(LIST_T) * (l.capacity << 1)); // x << 1 = x * 2
		for (unsigned int i = 0; i < l.capacity; i++) {
			new_buffer[i] = l.buffer[i];
		}
		l.capacity = l.capacity << 1;
	}
	l.head = (l.head - 1) % l.capacity;
	l.buffer[l.head] = x;
	return l;
}

List list_remove_head(List l) {
	l.length--;
	l.head = (l.head + 1) % l.capacity;
	return l;
}

void list_display(List l, char *buffer) {
	buffer  += sprintf(buffer, "[%d]", list_length(l));
	Place iter = list_head(l);
	for (unsigned int i = 0; i < list_length(l); (++i, iter = list_next(l, iter))) {
		buffer += sprintf(buffer, "->%d", list_get(l, iter));
	}
}
