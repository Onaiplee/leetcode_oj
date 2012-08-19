// Given two sorted integer arrays A and B, merge B 
// into A as one sorted array.
// 
// Note:
// You may assume that A has enough space to hold 
// additional elements from B. The number of elements 
// initialized in A and B are m and n respectively.

/**
 * I will add some comments later.
 */

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Shift A to the right n positions
        for (int i = 0; i < m; i++) {
            A[m+n-1-i] = A[m-1-i]; 
        }
        
        merge_one(&A[n], m, B, n, A);
        
    }
    
    void merge_one(int arr1[], int sz1, int arr2[], int sz2, int *buf) {
        if (!sz1 || !sz2) {
            if (sz1) {
                *buf = arr1[0];
                merge_one(arr1 + 1, sz1 - 1, arr2, sz2, buf + 1);
                return;
            }
            else if (sz2) {
                *buf = arr2[0];
                merge_one(arr1, sz1, arr2 + 1, sz2 - 1, buf + 1);
                return;
            }
            else {
                return;
            }
            
        }
        
        if (arr1[0] < arr2[0]) {
            *buf = arr1[0];
            merge_one(arr1 + 1, sz1 - 1, arr2, sz2, buf + 1);
        }
        else {
            *buf = arr2[0];
            merge_one(arr1, sz1, arr2 + 1, sz2 - 1, buf + 1);
        }
    }
};
