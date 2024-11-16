#include <stdio.h>
#include <stdlib.h>

int main() {
	signed char age = 18;
	if (age < 0) {
		printf("Soyez patient(e), votre tour arrive");
		return EXIT_SUCCESS;
	} else if (age < 18) {
		printf("Mineur");
		return EXIT_SUCCESS;
	} else if (age == 18) {
		printf("Tout juste majeur");
		return EXIT_SUCCESS;
	} else {
		printf("Majeur");
		return EXIT_SUCCESS;
	}
	printf("Et la surpopulation alors ?");
	return EXIT_SUCCESS;
}