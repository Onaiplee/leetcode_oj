// Given a linked list, remove the nth node from the end of list and return its head.
// 
// For example,
// 
//    Given linked list: 1->2->3->4->5, and n = 2.
// 
//    After removing the second node from the end, the linked list becomes 1->2->3->5.
// 
// Note:
// Given n will always be valid.
// Try to do this in one pass.

/**
 * NOTE: This algorithm assume the list are created on stack that will be automatically
 * destroyed properly.
 *
 * I use a recursive approach to practice coding skill. I will add a iterative approach
 * later and put it in alternatives/.
 */

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *pos = NULL;
        ListNode *p = NULL;

        if (head == NULL || head->next == NULL) {
            return NULL;
        }
        
        // Up to here, list has to have 2 or more elements.
        // So it's SAFE to use pos->next->next. IMPORTANT.
        if (n != 1) {
            // rpos can find the reverse nth element.
            // we can delete the element unless it's the last one.
            rpos(head, n, &pos);
            if (pos) {
                pos->val = pos->next->val;
                pos->next = pos->next->next;
            }
        }
        else {
            // Delete the last element.
            pos = head;
            while (pos->next->next != NULL) {
                pos = pos->next;
            }
            pos->next = NULL;
        }
        return head;
    }

    int rpos(ListNode *head, int n, ListNode **ret) {
        if (head == NULL) {
            return 1;
        }
        int level = rpos(head->next, n, ret);
        if (n == level) {
            *ret = head;
        }
        return 1 + level;
    }
};
