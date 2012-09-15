// Given a linked list, swap every two adjacent nodes and return its head.

// For example,
// Given 1->2->3->4, you should return the list as 2->1->4->3.

// Your algorithm should use only constant space. You may not modify the 
// values in the list, only nodes itself can be changed.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/**
 * I always like to add a pivot when I do such problems iteratively.
 * I added the recursive solution that is neat.
 */

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        ListNode *pivot = new NodeList(0);
        pivot->next = head;
        head = pivot;
        ListNode *l = NULL;
        ListNode *r = NULL;
        while(head->next && head->next->next) {
            l = head->next;
            r = head->next->next;
            l->next = r->next;
            r->next = l;
            head->next = r;
            head = l;
        }
        head = pivot->next;
        delete pivot;
        pivot = NULL;
        return head;
    }
};

/** 
 *recursive solution
 */

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        ListNode *l;
        ListNode *r;
        if (!head || !head->next) {
            return head;
        }
        else {
            l = head;
            r = head->next;
            l->next = swapPairs(r->next);
            r->next = l;
            return r;
        }
    }
};
