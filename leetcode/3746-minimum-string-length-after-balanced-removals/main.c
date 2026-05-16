#include "leetcode.h"

#include <stdio.h>
#include <string.h>

int minLengthAfterRemovals( char *s );

int main( ) {
	char lineBuff[256];

	while ( fgets( lineBuff, sizeof( lineBuff ), stdin ) ) {
		int i		= strcspn( lineBuff, "\n" );
		lineBuff[i] = '\0';

		int n = minLengthAfterRemovals( lineBuff );
		printf( "%d\n", n );
	}

	return 0;
}

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
