// Given a sorted array, remove the duplicates in place such that 
// each element appear only once and return the new length.
// 
// Do not allocate extra space for another array, you must do this 
// in place with constant memory.
// 
// For example,
// Given input array A = [1,1,2],
// 
// Your function should return length = 2, and A is now [1,2].

/**
 * keep loop invariant. (key point to write a correct program)
 * I use {} to denote loop invariant.
 */

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }

        int l = 1;
        int u = 1;
/*
 *      { A[0..(1-1)] must be an array without duplicates }
 *      { A[1..(1-1)] must be duplicates. A[1..0] is empty actually }
 */       
        while (u < n) {
/*
 *          { A[0..l-1] must be an array without duplicates }
 *          { A[l..u-1] must be duplicates. }
 */ 
            while (u < n && A[u] == A[u-1]) {
                u++;
            }
            if (u < n) {
                A[l] = A[u];
                l++;
                u++;
            }
        }
/*
 *      { A[0..l-1] must be an array without duplicates }
 *      { A[l..n-1] must be duplicates. }
 */       
        return l;
        // So we know this algorithm is CORRECT!
    }
};
