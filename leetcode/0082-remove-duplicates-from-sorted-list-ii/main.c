#include "leetcode.h"

#include <stdio.h>
#include <string.h>

struct ListNode *deleteDuplicates( struct ListNode *head );

int main( ) {
	char lineBuff[256];
	while ( fgets( lineBuff, sizeof( lineBuff ), stdin ) ) {
		int i			   = strcspn( lineBuff, "\n" );
		lineBuff[i]		   = '\0';
		ListNode		*l = lc_parse_list( lineBuff );
		struct ListNode *r = deleteDuplicates( l );

		lc_list_print( r );
	}
	return 0;
}

struct ListNode *deleteDuplicates( struct ListNode *head ) {
	struct ListNode dumby;
	dumby.next = head;
	dumby.val  = -1000;

	struct ListNode *slow = &dumby, *fast = dumby.next;
	while ( fast && fast->next ) {
		if ( fast->val == fast->next->val ) {
			int v = fast->val;

			while ( fast && fast->val == v ) {
				fast = fast->next;
			}

			slow->next = fast;
		} else {
			slow = fast;
			fast = fast->next;
		}
	}

	return dumby.next;
}
