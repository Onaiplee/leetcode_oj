// Given inorder and postorder traversal of a tree, construct the binary tree.
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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return build_tree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
    
    TreeNode *build_tree(vector<int> &inorder, int il, int ir, vector<int> &postorder, int pl, int pr) {
        if (il > ir || pl > pr) {
            return NULL;
        }
        TreeNode *aNode = new TreeNode(postorder[pr]);
        for (int i = il; i <= ir; i++) {
            if (inorder[i] == postorder[pr]) {
                aNode->left = build_tree(inorder, il, i - 1, postorder, pl, pl + i - il - 1);
                aNode->right = build_tree(inorder, i + 1, ir, postorder, pl + i - il, pr - 1);
                break;
            }
        } 
    } 
};
