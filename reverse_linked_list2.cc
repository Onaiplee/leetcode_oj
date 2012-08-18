// Reverse a linked list from position m to n. 
// Do it in-place and in one-pass.
// 
// For example:
// Given 1->2->3->4->5->NULL, m = 2 and n = 4,
// 
// return 1->4->3->2->5->NULL.
// 
// Note:
// Given m, n satisfy the following condition:
// 1 ≤ m ≤ n ≤ length of list.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/**
 * I will add some comments later.
 */

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *next = NULL;
        ListNode *pre = NULL;
        ListNode *le = NULL;
        ListNode *re = NULL;
        ListNode *current = head;
        ListNode *ret = head;
        if ((!head || head->next == NULL)) {
            return head;
        }
        for(int i = 1; i <= n; i++) {
            if (i == m - 1) {
                le = current;
                next = current->next;
            }
            else if (i == m) {
                next = current->next;
                re = current;
            }
            else if (i > m && i < n ) {
                next = current->next;
                current->next = pre;
            }
            else if (i == n) {
                re->next = current->next;
                current->next = pre;
                if (!le) {
                    ret = current;
                }
                else {
                    le->next = current;
                }
            }
            else {
                next = current->next;
            }
            pre = current;
            current = next;
            
        }
        return ret;
    }
};
