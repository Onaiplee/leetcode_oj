// Given a singly linked list where elements are sorted in ascending 
// order, convert it to a height balanced BST.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/**
 * I will add some comments later.
 */

class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {        
        if (!head) {
            return NULL;
        }
        if (!head->next) {
            return new TreeNode(head->val);
        }
        int size = length(head);
        int mid = size / 2;
        ListNode *mid_node = nthNode(head, mid);
        TreeNode *aNode = new TreeNode(mid_node->next->val);
        aNode->right = sortedListToBST(mid_node->next->next);
        mid_node->next = NULL;
        aNode->left = sortedListToBST(head);
        return aNode;
    }

    int length(ListNode *head) {
        if (!head) {
            return 0;
        }
        return 1 + length(head->next);
    }

    ListNode *nthNode(ListNode *head, int nth) {
        for (int i = 1; i < nth; i++) {
            head = head->next;
        }
        return head;
    }
};
