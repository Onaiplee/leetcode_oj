// Given a binary tree, determine if it is a valid binary 
// search tree (BST).
// 
// Assume a BST is defined as follows:
// 
// The left subtree of a node contains only nodes with keys 
// less than the node's key.

// The right subtree of a node contains only nodes with keys 
// greater than the node's key.
// Both the left and right subtrees must also be binary search trees.

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
 * I will add recursive solution later.
 */

class Solution {
public:
    bool isValidBST(TreeNode *root) {
        stack<TreeNode *> st;
        TreeNode *current = root;
        int last = INT_MIN;
        while (current || !st.empty()) {
            if (current) {
                st.push(root);
                current = root->left;
            }
            else {
                if (st.top()->val <= last) {
                    return false;
                }
                last = st.top()->val;
                current = st.top()->right;
                st.pop();
            }
        }
    }
};
