// Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
// 
// For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
// the contiguous subarray [4,−1,2,1] has the largest sum = 6.
// 
// More practice:
// If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

/**
 * This is a typical PAC-man Dynamic programming problem. 
 * We can define L[0..n-1]. A[i] stores largest sum of all the sub-array ending at i.
 * So we can get following recursive equation: 
 *     L[i] = max{L[i-1] + A[i], A[i]}
 * Note the L[i] depend only on L[i-1] so we can use just one variable to do the iteration, 
 * which leads to O(n) time and O(1) space.
 * I will add divide-and-conquer approach in alternative/ later.
 */

class Solution {
public:
    int maxSubArray(int A[], int n) {
        int a = A[0];
        int max = a;
        for (int i = 1; i < n; i++) {
            a = a + A[i] < A[i]? A[i] : a + A[i];
            max = a > max? a : max;
        }
        return max;
    }
};
