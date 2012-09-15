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
    ListNode *partition(ListNode *head, int x) {
        ListNode *l = new ListNode(INT_MAX);
        ListNode *u = new ListNode(INT_MAX);
        ListNode *le = l;
        ListNode *ue = u;
        while (head) {
            if (head->val < x) {
                le->next = head;
                le = head;
                head = head->next;
                le->next = NULL;
            }
            else {
                ue->next = head;
                ue = head;
                head = head->next;
                ue->next = NULL;
            }
        }
        le->next = u->next;
        delete u;
        u = NULL;
        head = l->next;
        delete l;
        l = NULL;
        return head;
    }
};
