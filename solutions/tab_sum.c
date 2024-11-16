int somme(int array[], int taille) {
	int sum = 0;
	for (int i = 0; i < taille; i++) {
		sum += array[i];
	}
	return sum;
}