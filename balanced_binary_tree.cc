// Given a binary tree, determine if it is height-balanced.
// 
// For this problem, a height-balanced binary tree is defined 
// as a binary tree in which the depth of the two subtrees of 
// every node never differ by more than 1.

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
 * This solution is a little bit tricky. This solution is post originally 
 * from the CareerCup150 Problem4-2.
 */

class Solution {
public:
    bool isBalanced(TreeNode *root) {
        if (dfs(root) >= 0) {
            return true;
        }
        return false;
    }

    int dfs(TreeNode *root) {
        if (!root) {
            return 0;
        }
        int left = dfs(root->left);
        if (left == -1) {
            return -1;
        }
        int right = dfs(root->right);
        if (right == -1) {
            return -1;
        }
        if (abs(left - right) > 1) {
            return -1;
        }
        return 1 + max(left, right);
    }
};
