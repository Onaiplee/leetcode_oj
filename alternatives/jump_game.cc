// Given an array of non-negative integers, you are initially positioned at the first index of the array.
// 
// Each element in the array represents your maximum jump length at that position.
// 
// Determine if you are able to reach the last index.
// 
// For example:
// A = [2,3,1,1,4], return true.
// 
// A = [3,2,1,0,4], return false.

/**
 * I will add some comments later.
 * This is a DFS approach, but it's not that efficient.
 */

class Solution {
public:
    bool canJump(int A[], int n) {
        return dfs(A, 0, n);
    }
    
    bool dfs(int A[], int current, int n) {
        if (current + A[current] >= n-1) {
            return true;
        }
        int max = A[current];
        for (int i = max; i > 0; i--) {
            if (dfs(A, current+i, n)) {
                return true;
            }
        }
        return false;
    }
};
