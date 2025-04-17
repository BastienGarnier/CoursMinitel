int atoi(char* string) {
	if (string == NULL) {
		return 0;
	}
	int x = 0;
	while (*string == ' ') {
		string++;
	}
	char sign = (*string == '-');
	if (*string == '-' || *string == '+') {
		string++;
	}
	while (*string <= '9' && *string >= '0') {
		x = 10*x + (*string++ - '0');
	}
	return (sign) ? -x : x;
}