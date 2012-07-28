// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

// For example, given n = 3, a solution set is:

// "((()))", "(()())", "(())()", "()(())", "()()()"


/* 
 * I will add some comments later
 */

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<char> s;
        vector<string> ret;
        dfs(s, n, 0, 0, ret);
        return ret;
    }
    
    void dfs(vector<char> &s, int n, int left, int right, vector<string> &result) {
        if (s.size() == n * 2) {
            result.push_back(string(s.begin(), s.end()));
        }
        else {
            if (left < n) {
                s.push_back('(');
                dfs(s, n, left + 1, right, result);
                s.pop_back();
            }
 
            if (left > right) {
                s.push_back(')');
                dfs(s, n, left, right + 1, result);
                s.pop_back();
            }
        }
    }
};
