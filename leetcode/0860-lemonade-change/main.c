#include "leetcode.h"

#include <stdio.h>
#include <string.h>

bool lemonadeChange( int *bills, int billsSize );

int main( ) {
	char lineBuff[256];

	while ( fgets( lineBuff, sizeof( lineBuff ), stdin ) ) {
		int i		= strcspn( lineBuff, "\n" );
		lineBuff[i] = '\0';
		int	 len	= 0;
		int *arr	= lc_parse_array( lineBuff, &len );

		bool r = lemonadeChange( arr, len );

		r ? printf( "true\n" ) : printf( "false\n" );
	}

	return 0;
}

bool lemonadeChange( int *bills, int billsSize ) {
	int i = 0, q5 = 0, q10 = 0, change = 0;

	for ( i = 0; i < billsSize; i++ ) {
		change = bills[i] - 5;

		if ( change == 5 ) {
			if ( q5 < 1 )
				return false;
			else
				q5 -= 1;
		} else if ( change == 15 ) {
			if ( q5 < 3 && ( q10 < 1 || q5 < 1 ) ) {
				return false;
			} else if ( q10 >= 1 && q5 >= 1 ) {
				q10 -= 1;
				q5 -= 1;
			} else if ( q5 >= 3 ) {
				q5 -= 3;
			}
		}

		if ( bills[i] == 5 )
			q5 += 1;
		else if ( bills[i] == 10 )
			q10 += 1;
	}

	return true;
}
