// Given a binary tree, return the inorder traversal of its nodes' values.
// 
// For example:
// Given binary tree {1,#,2,3},
//    1
//     \
//      2
//     /
//    3
// return [1,3,2].
// 
// Note: Recursive solution is trivial, could you do it iteratively?

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
 * I will add iterative solution later.
 */

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        inorder(root, result);
        return result;
        
    }
    
    void inorder(TreeNode *root, vector<int> &buf) {
        if (!root) {
            return;
        }
        else {
            inorder(root->left, buf);
            buf.push_back(root->val);
            inorder(root->right, buf);
        }
    }
};
