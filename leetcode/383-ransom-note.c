bool canConstruct(char* ransomNote, char* magazine) {
	int psmA[256], psmB[256], a = 0, b = 0;
	memset(psmA, 0, sizeof(psmA));
	memset(psmB, 0, sizeof(psmB));

	while (ransomNote[a] != '\0' || magazine[b] != '\0') {
		if (ransomNote[a] != '\0') {
			psmA[(int)ransomNote[a]] += 1;
			a += 1;
		}
		if (magazine[b] != '\0') {
			psmB[(int)magazine[b]] += 1;
			b += 1;
		}
	}

	for (int i = 0; i < 256; i++) {
		if (psmB[i] < psmA[i])
			return false;
	}

	return true;
}
