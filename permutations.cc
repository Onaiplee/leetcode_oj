// Given a collection of numbers, return all possible permutations.
// 
// For example,
// [1,2,3] have the following permutations:
// [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].

/**
 * I will add some comments later.
 */

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > result;
        dfs(result, num, 0);
        return result;
        
    }
    
    void dfs(vector<vector<int> > &result, vector<int> &num, int depth) {
        if (depth == num.size()) {
            result.push_back(num);
            return;
        }
        int temp;
        for (int i = depth; i < num.size(); i++) {
            temp = num[depth];
            num[depth] = num[i];
            num[i] = temp;
            dfs(result, num, depth + 1);
            temp = num[depth];
            num[depth] = num[i];
            num[i] = temp;
        }
    }
};
