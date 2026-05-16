#include "leetcode.h"

#include <stdio.h>
#include <string.h>

int tribonacci( int n );

int main( ) {
	char lineBuff[256];

	while ( fgets( lineBuff, sizeof( lineBuff ), stdin ) ) {
		int i		= strcspn( lineBuff, "\n" );
		lineBuff[i] = '\0';

		int n = 0;
		sscanf( lineBuff, "%d", &n );

		printf( "%d\n", tribonacci( n ) );
	}

	return 0;
}

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
