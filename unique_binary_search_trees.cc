// Given n, how many structurally unique BST's 
// (binary search trees) that store values 1...n?
// 
// For example,
// Given n = 3, there are a total of 5 unique BST's.

/**
 * I will add some comments later.
 */

class Solution {
public:
    int numTrees(int n) {
        int total = 0;
        if (!n) {
            return 1;
        }
        else {
            for (int i = 1; i <= n; i++) {
                total += numTrees(i-1) * numTrees(n-i);
            }
            return total;
        }
    }
};
