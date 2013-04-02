/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

/**
 * I will add some comments later.
 */

class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *level_start = root;
        TreeLinkNode *last = NULL;
        while (level_start) {
            TreeLinkNode *current = level_start;
            level_start = NULL;
            last = NULL;
            while (current) {
                if (current->left || current->right) {
                    if (current->left && current->right) {
                        if (!level_start) {
                            level_start = current->left;
                        }
                        current->left->next = current->right;
                        if (last) {
                            last->next = current->left;
                        }
                        last = current->right;
                    }
                    else {
                        if (current->left) {
                            if (!level_start) {
                                level_start = current->left;
                            }
                            if (last) {
                                last->next = current->left;
                            }
                            last = current->left;
                        }
                        else {
                            if (!level_start) {
                                level_start = current->right;
                            }
                            if (last) {
                                last->next = current->right;
                            }
                            last = current->right;
                        }
                    }
                }
                current = current->next;
            }
        }
    }
    
};
