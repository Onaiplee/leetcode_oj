// Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

// The same repeated number may be chosen from C unlimited number of times.

// Note:
// All numbers (including target) will be positive integers.
// Elements in a combination (a1, a2, … ,ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
// The solution set must not contain duplicate combinations.
// For example, given candidate set 2,3,6,7 and target 7, 
// A solution set is: 
// [7] 
// [2, 2, 3] 

/*
 * I will add some comments later.
 */

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > result;
        vector<int> buffer;
        dfs(0, 0, target, candidates, buffer, result);
        return result;
    }
    
    void dfs(int depth, int sum, int target, vector<int> &candidates, vector<int> &buffer, vector<vector<int> > &result) {
        if (sum > target)
            return;

        if (sum == target)
            store_result(candidates, buffer, result);

        // Define partition position
        int partition;
        if (depth == 0)
            partition = 0;
        else
            partition = buffer[depth-1];

        // Only candidates[partition..N] will be used in the next level, which avoid duplicates.
        for (int i = partition; i < candidates.size; i++) {
            buffer.push_back(i);
            dfs(depth + 1, sum + candidates[i], target, candidates, buffer, result);
            buffer.pop_back();
        }
        
    }
    
    void store_result(vector<int> &candidates, vector<int> &buffer, vector<vector<int> > &result) {
        vector<int> temp;
        int size = buffer.size();
        for (int i = 0; i < size; i++) {
            temp.push_back(candidates[buffer[i]]);
        }
        result.push_back(temp);
    }
};
