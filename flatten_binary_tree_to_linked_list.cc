// Given a binary tree, flatten it to a linked list in-place.
// 
// For example,
// Given
// 
//          1
//         / \
//        2   5
//       / \   \
//      3   4   6
// The flattened tree should look like:
//    1
//     \
//      2
//       \
//        3
//         \
//          4
//           \
//            5
//             \
//              6
// Hints:
// If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.

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
    void flatten(TreeNode *root) {
        if (!root) {
            return;
        }
        stack<TreeNode *> st;
        TreeNode *current = root;
        while (current->left || current->right || !st.empty()) {
            if (!current->left && !current->right) {
                current->right = st.top();
                st.pop();
            }
            else if (current->left && current->right) {
                st.push(current->right);
                current->right = current->left;
                current->left = NULL;
            }
            else if (current->left) {
                current->right = current->left;
                current->left = NULL;
            }
            current = current->right;
        }
    }
};
