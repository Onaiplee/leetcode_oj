// Write a function to find the longest common prefix string amongst an array of strings.

/**
 * I will add some comments later.
 */

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.size() == 0) {
            return string("");
        }

        int size = strs.size();
        int min = ~0 ^ (1 << 31);
        for (int i = 0; i < strs.size(); i++) {
            if (strs[i].size() < min) {
                min = strs[i].size();
            } 
        }
        int p = -1;
        int i;
        for (i = 0; i < min; i++) {
            int x = strs[0][i];
            int j;
            for (j = 1; j < strs.size(); j++) {
                if (strs[j][i] != x) {
                    break;
                }
            }
            if (j != strs.size()) {
                p = i - 1;
                break;
            }
        }
        if (i == min) {
            return strs[0].substr(0, min);
        }
        else {
            return strs[0].substr(0, p+1);   
        }
    }
};
