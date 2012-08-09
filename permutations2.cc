// Given a collection of numbers that might contain duplicates, 
// return all possible unique permutations.
// 
// For example,
// [1,1,2] have the following unique permutations:
// [1,1,2], [1,2,1], and [2,1,1].

/**
 * I will add some comments later.
 */

class Solution {
public:

    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > result;
        dfs(result, num, 0);
        return result;
        
    }
    
    void dfs(vector<vector<int> > &result, vector<int> &num, int depth) {
        if (depth == num.size()) {
            result.push_back(num);
            return;
        }
        set<int> s;
        int temp;
        for (int i = depth; i < num.size(); i++) {
            if (s.insert(num[i]).second) {
                swap(num[depth], num[i]);
                dfs(result, num, depth + 1);
                swap(num[depth], num[i]);
            }
        }
    }
    
    void swap(int &i, int &j) {
        int temp;
        temp = i;
        i = j;
        j = temp;
    }
};
