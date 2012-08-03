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
 */

class Solution {
public:
    bool canJump(int A[], int n) {
        // p is the farthest postion we can get.
        int p = 0;
        for (int i = 0; i <= p; i++) {
            if (A[i]+i > p) {
                p = A[i]+i < (n-1)? A[i]+i : (n-1);
            }
        }
        return p == n-1;
    }
};
