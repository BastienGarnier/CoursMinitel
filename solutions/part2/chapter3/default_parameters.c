#include <stdlib.h>
#include <stdio.h>

typedef struct add_r_opt {
	int r;
} add_r_opt;
int add_r_(int a, int b, add_r_opt opt) {
	return a + b + opt.r;
}
#define add_r(a, b, ...) add_r_(a, b, (add_r_opt){.r=0, __VA_ARGS__})

struct atoi_opt  {
	unsigned int base;
};
int atoi_(char* string, struct atoi_opt opt) {
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
	while (*string <= '0' + opt.base - 1 && *string >= '0') {
		x = opt.base*x + (*string++ - '0');
	}
	return (sign) ? -x : x;
}
#define atoi(string, ...) atoi_(string, (struct atoi_opt){.base=10, __VA_ARGS__})

int main() {
	printf("%d\n", add_r(4, 5));
	printf("%d\n", add_r(4, 5, .r = 1));

	printf("%d\n", atoi("87"));
	printf("%d\n", atoi("-1001", .base = 2));
	return EXIT_SUCCESS;
}