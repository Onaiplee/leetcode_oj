// Given a set of distinct integers, S, return all possible subsets.
// 
// Note:
// Elements in a subset must be in non-descending order.
// The solution set must not contain duplicate subsets.
// For example,
// If S = [1,2,3], a solution is:
// 
// [
//   [3],
//   [1],
//   [2],
//   [1,2,3],
//   [1,3],
//   [2,3],
//   [1,2],
//   []
// ]

/**
 * I will add more solutions later.
 */

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int> > result;
        result.push_back(vector<int>());
        int size = S.size();       
        for (int i = 0; i < S.size(); i++) {
            int size = result.size();
            for (int j = 0; j < size; j++) {
                vector<int> temp = result[j];
                temp.push_back(S[i]);
                result.push_back(temp);
            }
        }
        return result;
    }
    
};

/**
 * Here is the dfs solution.
 */

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<int> buffer;
        vector<vector<int> > result;
        dfs(0, S, result, buffer);
        result.push_back(buffer);
        return result;
    }
    
    void dfs(int index, vector<int> &S, vector<vector<int> > &result, vector<int> &buffer) {
        for (int i = index; i < S.size(); i++) {
            buffer.push_back(S[i]);
            result.push_back(buffer);
            dfs(i+1, S, result, buffer);
            buffer.pop_back();
        }
    }
};
