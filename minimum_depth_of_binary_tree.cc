// Given a binary tree, find its minimum depth.
// 
// The minimum depth is the number of nodes along the shortest 
// path from the root node down to the nearest leaf node.

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
 * This is just typical post-order DFS. And BFS seems even better.
 */

class Solution {
public:
    int minDepth(TreeNode *root) {
        if (!root) {
            return 0;
        }
        if (!root->left || !root->right) {
            if (!root->left && !root->right) {
                return 1;
            }
            else if (root->left) {
                return 1 + minDepth(root->left);
            }
            else {
                return 1 + minDepth(root->right);
            }
        }
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};
