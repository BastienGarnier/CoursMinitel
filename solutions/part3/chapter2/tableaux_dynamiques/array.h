#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED

#include <stdlib.h>

typedef int Element;

typedef struct Array {
	Element* a;
	unsigned int length;
} Array;

Array array_new(unsigned int length);
void array_destroy(Array arr);
Array array_copy(Array arr);
Element array_read(Array arr, unsigned int i);
void array_write(Array arr, unsigned int i, Element e);
unsigned int array_length(Array arr);
void array_resize(Array *arr, unsigned int n);

#endif