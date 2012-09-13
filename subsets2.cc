// Given a collection of integers that might contain duplicates, S, return all possible subsets.
// 
// Note:
// Elements in a subset must be in non-descending order.
// The solution set must not contain duplicate subsets.
// For example,
// If S = [1,2,2], a solution is:
// 
// [
//   [2],
//   [1],
//   [1,2,2],
//   [2,2],
//   [1,2],
//   []
// ]

/**
 * I will add some comments later.
 */

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<int> buffer;
        vector<vector<int> > result;
        dfs(0, S, result, buffer);
        result.push_back(buffer);
        return result;
    }
    
    void dfs(int index, vector<int> &S, vector<vector<int> > &result, vector<int> &buffer) {
        for (int i = index; i < S.size(); i++) {
            if (i-index > 0 && S[i] == S[i-1]) {
                continue;
            }
            buffer.push_back(S[i]);
            result.push_back(buffer);
            dfs(i+1, S, result, buffer);
            buffer.pop_back();
        }
    }
};
