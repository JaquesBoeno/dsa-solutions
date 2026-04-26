int minLengthAfterRemovals( char *s ) {
	int d = 0;

	for ( int i = 0; s[i] != '\0'; i++ ) {
		if ( s[i] == 'a' ) {
			d++;
		} else {
			d--;
		}
	}

	if ( d < 0 )
		return -d;
	else
		return d;
}
