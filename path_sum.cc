// Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
// 
// For example:
// Given the below binary tree and sum = 22,
//               5
//              / \
//             4   8
//            /   / \
//           11  13  4
//          /  \      \
//         7    2      1
// return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
 * I will add some comments later.
 */

class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        return dfs(root, sum, 0);
    }
    
    bool dfs(TreeNode *root, int sum, int acc) {
        if (!root) {
            return false;
        }
        acc += root->val;
        if (!root->left && !root->right) {
            if (acc == sum) {
                return true;
            }
        }
        bool ret = dfs(root->left, sum, acc);
        if (ret) {
            return true;
        }
        ret = dfs(root->right, sum, acc);
        if (ret) {
            return true;
        }
        return false;
    }
};
