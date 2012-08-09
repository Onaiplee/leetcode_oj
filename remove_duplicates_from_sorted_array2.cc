// Follow up for "Remove Duplicates":
// What if duplicates are allowed at most twice?
// 
// For example,
// Given sorted array A = [1,1,1,2,2,3],
// 
// Your function should return length = 5, and A is now [1,1,2,2,3].

/** 
 * I will add some comments later.
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
        
        // if there is already one
        int last = 0;
        for (int u = 1; u < n; u++) {
/*
 *          { A[0..l-1] must be an array with at most twice duplicates. } 
 *          { A[l..u-1] must be duplicates }          
 */           
            if (A[u] == A[u-1]) {
                if (last == 0) {
                    last = 1;
                    A[l] = A[u];
                    l++;
                }
                else {
                    last++;
                }
            }
            else {
                last = 0;
                A[l] = A[u];
                l++;
            }
        }
        return l;
    }
};
