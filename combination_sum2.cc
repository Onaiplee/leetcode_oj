// Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers 
// sums to T.

// Each number in C may only be used once in the combination.

// Note:
// All numbers (including target) will be positive integers.
// Elements in a combination (a1, a2, … ,ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
// The solution set must not contain duplicate combinations.
// For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
// A solution set is: 
// [1, 7] 
// [1, 2, 5] 
// [2, 6] 
// [1, 1, 6]


/*
 * I will add some comments later
 */

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int> > result;
        vector<int> buffer;
        sort(num.begin(), num.end());
        dfs(0, 0, num, target, buffer, result);
        return result; 
    }

    void dfs(int depth, int sum, vector<int> &num, int target, vector<int> &buffer, vector<vector<int> > &result) {
        if (sum > target)
            return;
        if (sum == target)
            store_result(num, buffer, result);

        // calculate the partition position
        int partition;
        if (depth == 0)
            partition = 0;
        else
            partition = buffer[depth-1] + 1;
        // Add num[partition..N] to next level except the duplicate number
        // The num[0..N] has been sorted so the duplicates are consecutive
        int last = -1;
        for (int i = partition; i < num.size(); i++) {
            // remove duplicates
            if (num[i] != last) {
                buffer.push_back(i);
                dfs(depth+1, sum + num[i], num, target, buffer, result);
                buffer.pop_back();
                last = num[i];
            }
        }
    }

    void store_result(vector<int> &num, vector<int> &buffer, vector<vector<int> > &result) {
        vector<int> temp;
        for (int i = 0; i < buffer.size(); i++) {
            temp.push_back(num[buffer[i]]);
        }
        result.push_back(temp);
    }
};
