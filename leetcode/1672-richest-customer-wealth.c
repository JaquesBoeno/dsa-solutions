int max( int a, int b ) {
	if ( a > b )
		return a;
	else
		return b;
}

int maximumWealth( int **accounts, int accountsSize, int *accountsColSize ) {
	int m = 0;

	for ( int i = 0; i < accountsSize; i++ ) {
		int cursum = 0;

		for ( int j = 0; j < *accountsColSize; j++ ) {
			cursum += accounts[i][j];
		}
		m = max( m, cursum );
	}

	return m;
}
