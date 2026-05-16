#include "leetcode.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isValid( char *s );

int main( ) {
	char lineBuff[256];

	while ( fgets( lineBuff, sizeof( lineBuff ), stdin ) ) {
		int i		= strcspn( lineBuff, "\n" );
		lineBuff[i] = '\0';
		bool r		= isValid( lineBuff );
		 r ? printf( "true\n" ) : printf( "false\n" );
	}

	return 0;
}

typedef struct Stack {
	char		  val;
	struct Stack *next;
} Stack;

Stack *push( Stack *stack, char val ) {
	Stack *new = malloc( sizeof( Stack ) );

	if ( new == NULL ) {
		return NULL;
	}

	new->next = stack;
	new->val  = val;

	return new;
}

Stack *pop( Stack *stack ) {
	Stack *s = stack->next;
	free( stack );
	return s;
}

char matching( char c ) {
	switch ( c ) {
		case ')':
			return '(';
		case ']':
			return '[';
		case '}':
			return '{';
		default:
			return '\0';
	}
}

bool isValid( char *s ) {
	Stack *stack = ( Stack * )malloc( sizeof( Stack ) );
	bool   valid = true;

	stack->next = NULL;
	stack->val	= '\0';

	for ( int i = 0; s[i] != '\0' && valid; i++ ) {
		char c = s[i];

		if ( c == '(' || c == '[' || c == '{' ) {
			stack = push( stack, c );
		} else if ( c == ')' || c == ']' || c == '}' ) {
			if ( matching( c ) != stack->val ) {
				return false;
			}

			stack = pop( stack );
		}
	}

	if ( stack->next != NULL ) {
		valid = false;
	}

	return valid;
}
