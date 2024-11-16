#include <stdio.h>
#include <stdlib.h>

#define N ...

int main() {
	unsigned int n = N;
	unsigned int f_m_1 = 0;
	unsigned int f_m_2 = 1;
	unsigned int tmp;
	for (; n > 0; n--) {
		tmp = f_m_1;
		f_m_1 = f_m_1 + f_m_2;
		f_m_2 = tmp;
	}
	printf("f(%u) = %u", N, f_m_1);
	return EXIT_SUCCESS;
}