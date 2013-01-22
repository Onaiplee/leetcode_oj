// Given an array where elements are sorted in ascending 
// order, convert it to a height balanced BST.

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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return sortedArray2Bst(num, 0, num.size() - 1);
    }

    TreeNode *sortedArray2Bst(vector<int> &num, int l, int r) {
        if (l > r) {
            return NULL;
        }
        TreeNode *aNode = new TreeNode(num[(l + r) / 2]);
        aNode->left = sortedArray2Bst(num, 0, l - 1);
        aNode->right = sortedArray2Bst(num, r + 1, num.size() - 1);
        return aNode;
    }
};
