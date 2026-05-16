#include "leetcode.h"

#include <stdio.h>
#include <string.h>

struct ListNode *removeNthFromEnd( struct ListNode *head, int n );

int main( ) {
	char lineBuff[256];
	char lineNum[64];

	while ( fgets( lineBuff, sizeof( lineBuff ), stdin ) != NULL ) {
		if ( fgets( lineNum, sizeof( lineNum ), stdin ) == NULL ) {
			break;
		}

		int i		= strcspn( lineBuff, "\n" );
		lineBuff[i] = '\0';
		ListNode *l = lc_parse_list( lineBuff );

		int n	   = 0;
		i		   = strcspn( lineNum, "\n" );
		lineNum[i] = '\0';
		sscanf( lineNum, "%d", &n );

		ListNode *r = removeNthFromEnd( l, n );
		lc_list_print( r );
	}

	return 0;
}

struct ListNode *removeNthFromEnd( struct ListNode *head, int n ) {
	struct ListNode dumby;
	dumby.next = head;
	dumby.val  = 0;

	struct ListNode *fast = &dumby, *slow = &dumby;

	for ( int i = 0; i < n; i++, fast = fast->next )
		;
	for ( ; fast->next; fast = fast->next, slow = slow->next ) {
	}

	slow->next = slow->next->next;

	return dumby.next;
}
