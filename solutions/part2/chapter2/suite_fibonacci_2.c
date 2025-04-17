#include <stdio.h>
#include <stdlib.h>

unsigned int fibo(int n) {
	unsigned int f_m_1 = 0;
	unsigned int f_m_2 = 1;
	unsigned int tmp;
	for (; n > 0; n--) {
		tmp = f_m_1;
		f_m_1 = f_m_1 + f_m_2;
		f_m_2 = tmp;
	}
	return f_m_1;
}
int main() {
	for (unsigned int n = 0; n <= 100; n++) {
		printf("fibo(%u) = %u\n", n, fibo(n));
	}
	return EXIT_SUCCESS;
}