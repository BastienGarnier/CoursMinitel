#include <stdio.h>

int somme(int array[], unsigned int length) {
	int sum = 0;
	for (unsigned int i = 0; i < length; i++) {
		sum += array[i];
	}
	return sum;
}

void display(int array[], unsigned int length) {
	for (unsigned int i = 0; i < length; i++) {
		printf("|%d|", array[i]);
	}
	printf("\n");
}

unsigned int max(int array[], unsigned int length) {
	unsigned int i_max = 0;
	for (int i = 1; i < length; i++) {
		i_max = array[i] > array[i_max] ? i : i_max;
	}
	return i_max;
}

unsigned int min(int array[], unsigned int length) {
	unsigned int i_min = 0;
	for (int i = 1; i < length; i++) {
		i_min = array[i] < array[i_min] ? i : i_min;
	}
	return i_min;
}

void swap(int array[], int i, int j) {
	int tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}

void selection_sort(int array[], unsigned int length) {
	for (unsigned int i = 0; i < length; i++) {
		unsigned int i_min = min(array + i, length - i);
		swap(array, i_min + i, i);
	}
}
