#include "array.h"

Array array_new(unsigned int length) {
	Array arr;
	arr.a = malloc(sizeof(Element) * length);
	arr.length = length;
	return arr;
}

void array_destroy(Array arr) {
	free(arr.a);
}

Array array_copy(Array arr) {
	Array arr_cpy;
	arr_cpy.a = malloc(sizeof(Element) * arr.length);
	for (unsigned int i = 0; i < arr.length; i++) {
		arr_cpy.a[i] = arr.a[i];
	}
	return arr_cpy;
}

Element array_read(Array arr, unsigned int i) {
	return arr.a[i];
}

void array_write(Array arr, unsigned int i, Element e) {
	arr.a[i] = e;
}

unsigned int array_length(Array arr) {
	return arr.length;
}

void array_resize(Array *arr, unsigned int n) {
	if (n == arr->length) {
		return; // évite la copie inutile si même taille. La spécification est bien respectée
	}
	Element *t = malloc(sizeof(Element) * n);
	unsigned int min = (n > arr->length) ? arr->length : n;
	for (unsigned int i = 0; i < min; i++) {
		t[i] = arr->a[i];
	}
	free(arr->a);
	arr->a = t;
	arr->length = n;
}