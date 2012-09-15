// Given a sorted array and a target value, return the index if the target is found. 
// If not, return the index where it would be if it were inserted in order.
// 
// You may assume no duplicates in the array.
// 
// Here are few examples.
// [1,3,5,6], 5 → 2
// [1,3,5,6], 2 → 1
// [1,3,5,6], 7 → 4
// [1,3,5,6], 0 → 0

/**
 * This is just a binary search. Neat!
 */

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        return bsearch(A, 0, n-1, target);
    }
    
    int bsearch(int A[], int l, int r, int target) {
        int m = (l + r) / 2;
        if (l > r) {
            return l;
        }
        else {
            if (target > A[m]) {
                return bsearch(A, m + 1, r, target);
            }
            else {
                return bsearch(A, l, m - 1, target);
            }
        }
    }
};	
