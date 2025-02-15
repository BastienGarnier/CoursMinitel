#include <stdio.h>
#include <stdlib.h>

char is_in(int x, int array[], unsigned int length) {
	unsigned int i_left = 0;
	unsigned int i_right = length;
	unsigned int i_mid = i_left + (i_right - i_left) / 2;
	while (i_mid > i_left) {
		if (array[i_mid] > x) { // x à gauche
			i_right = i_mid;
		} else if (array[i_mid] < x) {
			i_left = i_mid;
		} else {
			return 1;
		}
		i_mid = i_left + (i_right - i_left) / 2;
	}
	return array[i_mid] == x; // traite i_mid == i_left
}
