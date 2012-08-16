// There are two sorted arrays A and B of size m and n respectively. 
// Find the median of the two sorted arrays. The overall run time 
// complexity should be O(log (m+n)).

/**
 * I will add some comments later.
 */

class Solution {
public:
       double findMedianSortedArrays(int A[], int m, int B[], int n) {
           if (m == 0) {
                if (!(n % 2)) {
                    return (B[(n+1)/2-1] + B[(n+1)/2])/2.0;
                }
                else {
                    return B[(n+1)/2-1];
                }
            }
            else if (n == 0) {
                if (!(m % 2)) {
                    return (A[(m+1)/2-1] + A[(m+1)/2])/2.0;
                }
                else {
                    return A[(m+1)/2-1];
                }
            }
            else {
                return median_search(A, B, m, n, max(1, (m+n+1)/2 - n), min(m, (m+n+1)/2));
            }
        }


    double median_search(int A[], int B[], int l, int m, int left, int right) {
        if (left > right) {
            return median_search(B, A, m, l, max(1, (l+m+1)/2 - l), min(m, (l+m+1)/2));
        }
        int i = (left + right) / 2;
        int j = (l+m+1)/2 - i;
        if ((j == 0 || A[i-1] >= B[j-1]) && (j == m || A[i-1] <= B[j])) {
            if ((l+m)%2) {
                return A[i-1];
            }
            else {
                if (i > l - 1) {
                    return (A[i-1] + B[j])/2.0;
                }
                return (A[i-1] + min(A[i], B[j]))/2.0;
            }
        }
        else if ((j == 0 || A[i-1] >= B[j-1]) && (j != m && A[i-1] > B[j])) {
            return median_search(A, B, l, m, left, i - 1);
        }
        else {
            return median_search(A, B, l, m, i + 1, right);
        }
    }

    int max(int a, int b) {
        return a > b? a : b;
    }

    int min(int a, int b) {
        return a < b? a : b;
    }
};
