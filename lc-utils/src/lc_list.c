#include "leetcode.h"

static ListNode *new_node( int val ) {
	ListNode *n = malloc( sizeof( ListNode ) );
	if ( !n )
		return NULL;
	n->val	= val;
	n->next = NULL;
	return n;
}

ListNode *lc_parse_list( const char *s ) {
	if ( !s )
		return NULL;

	/* Reutiliza o parser de array de ints */
	int	 len = 0;
	int *arr = lc_parse_array( s, &len );
	if ( !arr || len == 0 ) {
		free( arr );
		return NULL;
	}

	/* Constrói a lista encadeada */

	ListNode dummy;
	dummy.next	  = NULL;
	ListNode *cur = &dummy;

	for ( int i = 0; i < len; i++ ) {
		cur->next = new_node( arr[i] );
		cur		  = cur->next;
	}

	free( arr );
	return dummy.next;
}

void lc_list_free( ListNode *head ) {
	while ( head ) {
		ListNode *tmp = head->next;
		free( head );
		head = tmp;
	}
}

void lc_list_print( ListNode *head ) {
	printf( "[" );
	while ( head ) {
		printf( "%d", head->val );
		if ( head->next )
			printf( "," );
		head = head->next;
	}
	printf( "]\n" );
}
