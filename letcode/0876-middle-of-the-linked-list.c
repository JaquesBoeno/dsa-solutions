/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head) {
	int				 i = 0;
	struct ListNode *a = head, *b = head;

	while (b != NULL) {
		if (i % 2 == 1) {
			b = b->next;
			a = a->next;
		} else {
			b = b->next;
		}
		i++;
	}

	return a;
}
