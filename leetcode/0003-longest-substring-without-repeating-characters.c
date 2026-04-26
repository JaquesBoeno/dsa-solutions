int max( int a, int b ) {
	if ( a > b )
		return a;
	else
		return b;
}

int lengthOfLongestSubstring( char *s ) {
	int m = 1, q = 0, l = 0, r = 0;
	int psm[256]; // Pseudo Hash Map
	memset( psm, -1, sizeof( psm ) );

	if ( s[0] == '\0' )
		return 0;

	for ( r = 0; s[r] != '\0'; r++ ) {
		if ( psm[( int )s[r]] >= l ) {
			m = max( m, r - l );
			l = psm[( int )s[r]] + 1;
		}

		psm[( int )s[r]] = r;
	}

	m = max( m, r - l );
	return m;
}
