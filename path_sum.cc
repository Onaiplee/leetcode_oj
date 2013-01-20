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

/**
 * I will add some comments later.
 */

class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > result;
        vector<int> path;
        int current = 0;
        dfs(root, sum, current, path, result);
        return result;
    }
    
    void dfs(TreeNode *root, int sum, int &current, vector<int> &path, vector<vector<int> > &result) {
        if (!root) {
            return;
        }
        path.push_back(root->val);
        current += root->val;
        if (!root->left && !root->right) {
            if (current == sum) {
                result.push_back(path);
            }
        }
        dfs(root->left, sum, current, path, result);
        dfs(root->right, sum, current, path, result);
        path.pop_back();
        current -= root->val;
        return;
    }
};
