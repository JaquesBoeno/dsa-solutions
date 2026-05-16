#include "leetcode.h"

#include <stdio.h>
#include <string.h>

int maximumWealth( int **accounts, int accountsSize, int *accountsColSize );

int main( ) {
	char lineBuff[256];
	while ( fgets( lineBuff, sizeof( lineBuff ), stdin ) ) {
		int i		   = strcspn( lineBuff, "\n" );
		lineBuff[i]	   = '\0';
		int	  qttRows  = 0, *qttCols;
		int **accounts = lc_parse_matrix( lineBuff, &qttRows, &qttCols );
		int	  r		   = maximumWealth( accounts, qttRows, qttCols );
		printf( "%d\n", r );
	}
	return 0;
}

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
