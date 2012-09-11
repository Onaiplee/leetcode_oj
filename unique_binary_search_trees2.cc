/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        vector<TreeNode *> result;
        result = generate(1, n);
        return result;
    }
    
    vector<TreeNode *> generate(int l, int u) {
        vector<TreeNode*> ret;
        if (l > u) {
            ret.push_back(NULL);
            return ret;
        }

        for (int i = l; i <= u; i++) {
            TreeNode *root = new TreeNode(0);
            root->val = i;
            vector<TreeNode*> l_trees = generate(l, i-1);
            vector<TreeNode*> r_trees = generate(i+1, u);

            for (int j = 0; j < l_trees.size(); j++) {
                for (int k = 0; k < r_trees.size(); k++) {
                    root->left = l_trees[j];
                    root->right = r_trees[k];    
                    ret.push_back(make_tree(root));
                }
            }

            // delete the trees since we have built new tress
            delete root;
            delete_trees(l_trees);
            delete_trees(r_trees);
        }
        return ret;
    }

    TreeNode *make_tree(TreeNode *root) {
        if (!root) {
            return NULL;
        }
        TreeNode *tree = new TreeNode(root->val);
        tree->left = make_tree(root->left);
        tree->right = make_tree(root->right);
        return tree;
    }

    void delete_trees(vector<TreeNode *> &trees) {
        for (int i = 0; i < trees.size(); i++) {
            delete trees[i];
        }
    }
};
