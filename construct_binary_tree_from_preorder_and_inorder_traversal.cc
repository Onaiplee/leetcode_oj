// Given preorder and inorder traversal of a tree, construct the binary tree.
//
// Note:
// You may assume that duplicates do not exist in the tree.

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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return build_tree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
    
    TreeNode *build_tree(vector<int> &preorder, int pl, int pr, vector<int> &inorder, int il, int ir) {
        if (pl > pr || il > ir) {
            return NULL;
        }
        TreeNode *aNode = new TreeNode(preorder[pl]);
        for (int i = il; i <= ir; i++) {
            if (preorder[pl] == inorder[i]) {
                aNode->left = build_tree(preorder, pl + 1, pl + i - il , inorder, il, i - 1);
                aNode->right = build_tree(preorder, pl + i - il + 1, pr, inorder, i + 1, ir);
                break;
            }
        }
    }
};
