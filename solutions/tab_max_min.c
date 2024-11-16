int max(int array[], int taille) {
	int m = array[0];
	for (int i = 1; i < taille; i++) {
		m = array[i] > m ? array[i] : m;
	}
	return m;
}

int min(int array[], int taille) {
	int m = array[0];
	for (int i = 1; i < taille; i++) {
		m = array[i] < m ? array[i] : m;
	}
	return m;
}