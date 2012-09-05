// Given two binary trees, write a function to check if 
// they are equal or not.
// 
// Two binary tree are considered equal if they are 
// structurally identical and the nodes have the same value.


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
 * I will add some comments.
 */

class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (!p || !q) {
            if (p == q) {
                return true;
            }
            else {
                return false;
            }
        }
        return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
