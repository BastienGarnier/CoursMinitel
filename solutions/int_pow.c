long int pow(int x, unsigned int n) {
	long int p = 1;
	for (; n > 0; n--) {
		p *= x;
	}
	return p;
}