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
 * I will add some comments later.
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

/**
 * The following code is the iterative solution.
 */

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        TreeNode *current;
        stack<TreeNode*> st;
        current = root;
        while (current || !st.empty()) {
            if (current) {
                st.push(current);
                current = current->left;
            }
            else {
                result.push_back(st.top()->val);
                current = st.top()->right;
                st.pop();
            }
        }
        return result;
    }
};
