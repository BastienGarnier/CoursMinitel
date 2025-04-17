unsigned int mult(unsigned int first, ...) {
	unsigned int product = first;
	va_list args;
	va_start(args, first);
	for (int x = va_arg(args, int); x != 0; x = va_arg(args, int)) {		
		product *= x;
	}
	va_end(args);
	return product;
}