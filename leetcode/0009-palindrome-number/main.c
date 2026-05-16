#include "leetcode.h"

#include <stdio.h>
#include <string.h>

bool isPalindrome( int x );

int main( ) {
	char lineBuff[256];

	while ( fgets( lineBuff, sizeof( lineBuff ), stdin ) ) {
		int i		= strcspn( lineBuff, "\n" );
		lineBuff[i] = '\0';
		int x		= 0;
		sscanf( lineBuff, "%d", &x );
		bool r = isPalindrome( x );
		r ? printf( "true\n" ) : printf( "false\n" );
	}

	return 0;
}

bool isPalindrome( int x ) {
	long int inv = 0, tmp = x;

	if ( x < 0 )
		return false;

	while ( tmp > 0 ) {
		inv = inv * 10 + ( tmp % 10 );
		tmp /= 10;
	}

	if ( x == inv )
		return true;

	return false;
}
