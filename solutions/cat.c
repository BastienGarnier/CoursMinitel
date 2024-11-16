#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	if (argc < 2) {
		fprintf(stderr, "Il faut donner en argument du programme le nom du fichier à afficher.\n");
	}
	FILE *f = fopen(argv[1], "r");
	if (f == NULL) {
		fprintf(stderr, "Erreur d'ouverture du fichier %s\n", argv[1]);
	}
	char buffer[1024] = {0};
	while (fread(buffer, 1, 1023, f) == 1023) {
		printf("%s", buffer);
	}
	printf("%s", buffer);
	return EXIT_SUCCESS;
}