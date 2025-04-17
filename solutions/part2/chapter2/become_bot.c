void mov(int *x, int val) {
	*x = val;
}

void add(int *a, int *b) {
	*a += *b;
}

void mul(int *y, int *z) {
	*y *= *b;
}

void pow(int *x, int n) {
	int p = 1;
	for (; n > 0; n--) {
		p *= *x;
	}
	*x = p;
}