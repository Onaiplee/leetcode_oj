// Given an unsorted integer array, find the first missing positive integer.
// 
// For example,
// Given [1,2,0] return 3,
// and [3,4,-1,1] return 2.

// Your algorithm should run in O(n) time and uses constant space.

/*
 * I will add some comments later.
 */

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        int temp;
        for (int i = 0; i < n; i++) {
            while (A[i] > 0 && A[i] <= n && A[i] != i+1) {
                // here the assignment sequence deos matter!
                // This sequence avoid Read-Write conflict.
                temp = A[A[i]-1];
                A[A[i]-1] = A[i];
                A[i] = temp;
            }
        }
        for (int i = 0; i < n; i++) {
            if (A[i] != i+1) {
                return i+1;
            }
        }
        return n+1;
    }
};
