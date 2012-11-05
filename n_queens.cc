// Given an integer n, return all distinct solutions to the n-queens puzzle.
// 
// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
//   
// For example,
// There exist two distinct solutions to the 4-queens puzzle:
// 
// [
//  [".Q..",  // Solution 1
//   "...Q",
//   "Q...",
//   "..Q."],
// 
//  ["..Q.",  // Solution 2
//   "Q...",
//   "...Q",
//   ".Q.."]
// ]

/**
 * This is a typical problem can be solved by DFS. DP is also possible but will consume more memory.
 */

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<int> arr(n, 0);
        for (int i = 0; i < n; i++) {
            arr[i] = i;
        }
        vector<vector<int> > result;
        dfs(result, arr, 0);
        vector<vector<string> > ans;
        for (int i = 0; i < result.size(); i++) {
            vector<string> vec; 
            for (int j = 0; j < result[i].size(); j++) {
                string s(n, '.');
                s[result[i][j]] = 'Q';
                vec.push_back(s);
            }
            ans.push_back(vec);
        }
        return ans;
    }
    
    void dfs(vector<vector<int> > &result, vector<int> &arr, int n) {
        if (n == arr.size() - 1) {
            if (valid(arr)) {
                result.push_back(arr);
            }
            return;
        }
        for (int i = n; i < arr.size(); i++) {
            swap(&arr[n], &arr[i]);
            dfs(result, arr, n + 1);
            swap(&arr[n], &arr[i]);
        }
    }
    
    void swap(int *a, int *b) {
        int temp;
        temp = *a;
        *a = *b;
        *b = temp;
    }
    
    bool valid(vector<int> &arr) {
        for (int i = 0; i < arr.size(); i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                if (abs(arr[i] - arr[j]) == abs(i - j)) {
                    return false;
                }
            }
        }
        return true;
    }
    
    int abs(int n) {
        return n > 0? n : -n;
    }
};
