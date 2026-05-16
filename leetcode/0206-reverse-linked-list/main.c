#include "leetcode.h"

#include <stdio.h>
#include <string.h>

struct ListNode *reverseList( struct ListNode *head );

int main( ) {
	char lineBuff[256];
	while ( fgets( lineBuff, sizeof( lineBuff ), stdin ) ) {
		int i		= strcspn( lineBuff, "\n" );
		lineBuff[i] = '\0';

		ListNode *l = lc_parse_list( lineBuff );
		ListNode *r = reverseList( l );

		lc_list_print( r );
	}

	return 0;
}

struct ListNode *reverseList( struct ListNode *head ) {
	struct ListNode *prev = NULL;
	struct ListNode *curr = head;
	struct ListNode *next = NULL;

	while ( curr != NULL ) {
		next	   = curr->next;
		curr->next = prev;
		prev	   = curr;
		curr	   = next;
	}

	return prev;
}
