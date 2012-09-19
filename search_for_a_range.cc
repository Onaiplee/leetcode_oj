// Given a sorted array of integers, find the starting and ending 
// position of a given target value.
// 
// Your algorithm's runtime complexity must be in the order of O(log n).
// 
// If the target is not found in the array, return [-1, -1].
// 
// For example,
// Given [5, 7, 7, 8, 8, 10] and target value 8,
// return [3, 4].

/**
 * I will add some comments later.
 */

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> result;
        int l = bsearch_l(A, 0, n - 1, target);
        int u = bsearch_r(A, 0, n - 1, target);
        if (A[l] == target && A[u] == target) {
            result.push_back(l);
            result.push_back(u);
        }
        else {
            result.push_back(-1);
            result.push_back(-1);
        }
        return result;
        
    }
    
    int bsearch_r(int A[], int l, int u, int target) {
        if (l > u) {
            return u;
        }
        int m = (l + u) / 2;
        if (A[m] < target) {
            return bsearch_r(A, m + 1, u, target);
        }
        else if (A[m] > target) {
            return bsearch_r(A, l, m - 1, target);
        }
        else {
            return bsearch_r(A, m + 1, u, target);
        }
    }
    
    int bsearch_l(int A[], int l, int u, int target) {
        if (l > u) {
            return l;
        }
        int m = (l + u) / 2;
        if (A[m] < target) {
            return bsearch_l(A, m + 1, u, target);
        }
        else if (A[m] > target) {
            return bsearch_l(A, l, m - 1, target);
        }
        else {
            return bsearch_l(A, l, m - 1, target);
        }
    }
    
};
