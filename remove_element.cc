// Given an array and a value, remove all instances of that value in place and return the new length.
// 
// The order of elements can be changed. It doesn't matter what you leave beyond the new length.class Solution {

public:
    int removeElement(int A[], int n, int elem) {
        int l = 0;
        for (int u = l; u < n; u++) {
            if (A[u] != elem) {
                A[l] = A[u];
                l++;
            }
        }
        return l;
    }
};
