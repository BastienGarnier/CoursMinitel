void swap(int *x, int *y) {
	if (x == y) {
		return;
	}
	*x = *x ^ *y;
	*y = *x ^ *y;
	*x = *x ^ *y;
}