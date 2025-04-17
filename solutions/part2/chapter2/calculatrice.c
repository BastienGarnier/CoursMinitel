#include <stdio.h>
#include <stdlib.h>

int main() {
	char op;
	double x;
	double y;
	while (1) {
		printf("> ");
		if (scanf("%lf %c %lf", &x, &op, &y) == 3) {
			switch (op) {
			case '+':
				printf("%lf\n", x + y);
				break;
			case '-':
				printf("%lf\n", x - y);
				break;
			case '/':
				printf("%lf\n", x / y);
				break;
			case '*':
				printf("%lf\n", x * y);
				break;
			}
		} else {
			fprintf(stderr, "Erreur !\n");
			return EXIT_FAILURE;
		}
	}

	return EXIT_SUCCESS;
}