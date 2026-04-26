int reverseDegree( char *s ) {
	int sum = 0;

	for ( int i = 0; s[i] != '\0'; i++ ) {
		sum += ( 26 - ( s[i] - 97 ) ) * ( i + 1 );
	}

	return sum;
}
