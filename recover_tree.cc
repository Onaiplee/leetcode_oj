// Two elements of a binary search tree (BST) are swapped by mistake.
// 
// Recover the tree without changing its structure.

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
 * This solution is way boring and not elegant... I will refactor it later...
 */

class Solution {
public:
    void recoverTree(TreeNode *root) {
        stack<TreeNode*> st;
        vector<TreeNode*> vec;
        TreeNode *current = root;
        while (current || !st.empty()) {
            if (current) {
                st.push(current);
                current = current->left;
            }
            else {
                vec.push_back(st.top());
                current = st.top()->right;
                st.pop();
            }
        }
        int i, j;
        for (i = 0; i < vec.size() - 1; i++) {
            if (vec[i]->val > vec[i+1]->val) {
                break;
            }
        }

        for (j = i + 2; j < vec.size(); j++) {
            if (vec[j]->val < vec[j-1]->val) {
                break;
            }
        }
        if (j < vec.size()) {
            swap(vec[i], vec[j]);
        }
        else {
            swap(vec[i], vec[i+1]);
        }
    }

    void swap(TreeNode *r1, TreeNode *r2) {
        int temp;
        temp = r1->val;
        r1->val = r2->val;
        r2->val = temp;
    }
};
