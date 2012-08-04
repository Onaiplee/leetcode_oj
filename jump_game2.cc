// Given an array of non-negative integers, you are initially positioned at the first index of the array.
// 
// Each element in the array represents your maximum jump length at that position.
// 
// Your goal is to reach the last index in the minimum number of jumps.
// 
// For example:
// Given array A = [2,3,1,1,4]
// 
// The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

/**
 * This is a DP problem and has O(n^2) time complexity. 
 * This one is correct but with poor readability...
 * I will give a more concise one later.
 */

class Solution {
public:
    int jump(int A[], int n) {
        int *best = (int *) malloc(n * sizeof(int));
        int result;
        int max = 10000;
        for (int i = 0; i < n; i++) {
            best[i] = max;
        }
        best[0] = 0;
        int p = 0;
        for (int i = 0; i <= p; i++) {
            if (i+A[i] > p) {
                p = i+A[i] < n-1? i+A[i] : n-1; 
            }
            for (int j = i+1; j <= p; j++) {
                if (1 + best[i] < best[j]) {
                    best[j] = 1 + best[i];
                }
            }
        }
        result = best[n-1];
        free(best);
        if (result != max) {
            return result;
        }
        else {
            return -1;
        }
    }
};
