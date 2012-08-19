// Merge k sorted linked lists and return it as one sorted list. 
// Analyze and describe its complexity.

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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int min = INT_MAX;
        int index = -1;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i]) {
                if (lists[i]->val <= min) {
                    min = lists[i]->val;
                    index = i;
                }
            }
        }
        if (index == -1) {
            return NULL;
        }
        ListNode *current = lists[index];
        lists[index] = lists[index]->next;
        current->next = mergeKLists(lists);
        return current;
    }
};
