#include <stdio.h>
#include <stdlib.h>

int main() {
	double xA, xB, yA, yB;
	printf("Entrer xA : ");
	scanf("%lf", &xA);
	printf("Entrer yA : ");
	scanf("%lf", &yA);
	printf("Entrer xB : ");
	scanf("%lf", &xB);
	printf("Entrer yB : ");
	scanf("%lf", &yB);
	printf("||A - B||^2 = %lf", (xA - xB)*(xA - xB) + (yA - yB)*(yA - yB));
	return EXIT_SUCCESS;
}