// Given a digit string, return all possible letter combinations that the number could represent.
// 
// A mapping of digit to letters (just like on the telephone buttons) is given below.
// 
// Input:Digit string "23"
// Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
// Note:
// Although the above answer is in lexicographical order, your answer could be in any order you want.

/**
 * I will add some comments later.
 */

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<char, string> table;
        vector<string> result;
        string buffer(digits);
        table['2'] = string("abc");
        table['3'] = string("def");
        table['4'] = string("ghi");
        table['5'] = string("jkl");
        table['6'] = string("mno");
        table['7'] = string("pqrs");
        table['8'] = string("tuv");
        table['9'] = string("wxyz");
        dfs(digits, 0, digits.size(), table, buffer, result);
        return result;
    }
    
    void dfs(string &digits, int depth, int size, map<char, string> &table, string &buffer, vector<string> &result) {
        if (depth == size) {
            result.push_back(buffer);
            return;
        }
        for (int i = 0; i < table[digits[depth]].size(); i++) {
            buffer[depth] = table[digits[depth]][i];
            dfs(digits, depth+1, size, table, buffer, result);
        }
    }
};
