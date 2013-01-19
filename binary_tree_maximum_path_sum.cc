// Given a binary tree, find the maximum path sum.
// 
// The path may start and end at any node in the tree.
// 
// For example:
// Given the below binary tree,
// 
//        1
//       / \
//      2   3
// Return 6.

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    int maxPathSum(TreeNode *root) {
        int maximum = INT_MIN;
        dfs(root, maximum);
        return maximum;
    }
    
    int dfs(TreeNode *root, int &maximum) {
        if (!root) {
            return 0;
        }
        int l = dfs(root->left, maximum);
        int r = dfs(root->right, maximum);
        int ret = max(root->val, root->val + max(l, r));
        int current = max(root->val, root->val + max(l + r, max(l, r)));
        if (current > maximum) {
            maximum = current;
        }
        return ret;
        
    }
};
