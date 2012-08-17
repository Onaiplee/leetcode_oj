// Given a string containing only digits, restore it by returning all 
// possible valid IP address combinations.
// 
// For example:
// Given "25525511135",
// 
// return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)

/**
 * I will refine this terrible code...
 */

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        int buffer[3] = {-1, -1, -1};
        vector<string> result;
        dfs(0, buffer, s, 0, result);
        return result;
    }
    
    void dfs(int depth, int buffer[], string &s, int current, vector<string> &ret) {
        if (!valid(s.size(), current, 4 - depth)) {
            return;
        }
        
        if (depth == 3 && valid(s.size(), current, 1) && (s2i(s, current, s.size() - 1) <= 255) && (current == s.size() - 1 || s[current] != '0')) {
            ret.push_back(generate_ip(buffer, s));
            return;
        }

        if (s[current] == '0') {
            buffer[depth] = current;
            dfs(depth+1, buffer, s, current+1, ret);
        } else {
            for (int i = current; i <= min(current+2, (int) s.size()-1); i++) {
                if (s2i(s, current, i) <= 255) {
                    buffer[depth] = i;
                    dfs(depth+1, buffer, s, i+1, ret);
                }
            }
        }
    }
    
    string generate_ip(int buffer[], string &s) {
        string ret;
        int j = 0;
        for (int i = 0; i < s.size(); i++) {
            ret.push_back(s[i]);
            if (i == buffer[j] && j < 3) {
                ret.push_back('.');
                j++;
            }
        }
        return ret;
    }
    
    bool valid(int size, int current, int field) {
        int remain = size - current;
        if (remain < field || remain > 3 * field) {
            return false;
        }
        else {
            return true;
        }
    }
    
    int s2i(string &s, int l, int u) {
        int p = 0;
        for (int i = l; i <= u; i++) {
            p = p*10 + (s[i] - '0');
        }
        return p;
    }
};
