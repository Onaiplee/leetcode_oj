// Follow up for N-Queens problem.
// 
// Now, instead outputting board configurations, return the total number of distinct solutions.

/**
 * To get the orignin n_queens code to pass the large test in leetcode, we need a little more optimization here.
 */

class Solution {
public:
    int totalNQueens(int n) {
        vector<int> arr(n, 0);
        for (int i = 0; i < n; i++) {
            arr[i] = i;
        }
        int result = 0;
        dfs(result, arr, 0);
        return result;
    }
    
    void dfs(int &result, vector<int> &arr, int n) {
        if (n == arr.size()) {
            result++;
            return;
        }
        for (int i = n; i < arr.size(); i++) {
            swap(&arr[n], &arr[i]);
            /* we don't have to dfs all the possibilities. */
            if (valid(arr, n)) {
                dfs(result, arr, n + 1);
            }
            swap(&arr[n], &arr[i]);
        }
    }
    
    void swap(int *a, int *b) {
        int temp;
        temp = *a;
        *a = *b;
        *b = temp;
    }
    
    bool valid(vector<int> &arr, int n) {
        for (int i = 0; i < n; i++) {
            if (abs(arr[i] - arr[n]) == abs(i - n)) {
                return false;
            }
        }
        return true;
    }
    
    int abs(int n) {
        return n > 0? n : -n;
    }
};
