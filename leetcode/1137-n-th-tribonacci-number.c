int tribonacci( int n ) {
	int a = 0, b = 1, c = 1, d = 0;
	if ( n == 0 )
		return 0;
	if ( n < 3 )
		return 1;

	for ( ; n > 2; n-- ) {
		d = a + b + c;
		a = b;
		b = c;
		c = d;
	}

	return d;
}
