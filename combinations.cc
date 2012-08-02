
// Given two integers n and k, return all possible combinations of k
// numbers out of 1 ... n.
// 
// For example, 
// If n = 4 and k = 2, a solution is:
//
// [
//   [2, 4],
//   [3, 4],
//   [2, 3],
//   [1, 2],
//   [1, 3],
//   [1, 4],
// ]

/*
 * I will add some comments later.
 */

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > result;
        vector<int> buffer;
        dfs(result, buffer, k, n, 0);
        return result;
    }
    
    void dfs(vector<vector<int> > &result, vector<int> &buffer, int depth,  int n, int s) {
        if (depth == 0) {
            result.push_back(buffer);
        }
        else {
            for (int i = s; i < n - depth + 1; i++) {
                buffer.push_back(i+1);
                dfs(result, buffer, depth - 1, n, i+1);
                buffer.pop_back();
            }
        }
    }
};
