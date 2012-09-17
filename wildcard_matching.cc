// Implement wildcard pattern matching with support for '?' and '*'.
// 
// '?' Matches any single character.
// '*' Matches any sequence of characters (including the empty sequence).
// 
// The matching should cover the entire input string (not partial).
// 
// The function prototype should be:
// bool isMatch(const char *s, const char *p)
// 
// Some examples:
// isMatch("aa","a") → false
// isMatch("aa","aa") → true
// isMatch("aaa","aa") → false
// isMatch("aa", "*") → true
// isMatch("aa", "a*") → true
// isMatch("ab", "?*") → true
// isMatch("aab", "c*a*b") → false

/**
 * The memoization solution consumes too much memory to pass the large OJ.
 * I will add a better solution later.
 */

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if (*s == '\0') {
            if (*p == '\0') {
                return true;
            }
            else if (*p == '*') {
                return isMatch(s, p+1);
            }
            else {
                return false;
            }
        }
        if (make_a_parse(s, p)) {
            if (*p == '*') {
                return isMatch(s, p+1) || isMatch(s+1, p) || isMatch(s+1, p+1);
            }
            else {
                return isMatch(s+1, p+1);
            }
        }
        else {
            return false;
        }
    }
    
    bool make_a_parse(const char *s, const char *p) {
        if (((*p == '?'|| *s == *p) && *s != '\0') || *p == '*' ) {
            return true;
        }
        return false;
    }
};

/**
 * DP using memoization.
 */

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        vector<vector<int> > table(strlen(s) + 1, vector<int>(strlen(p) + 1, -1));
        return is_match(s, p, table, 0, 0)? true : false;
    }

    int is_match(const char *s, const char *p, vector<vector<int> > &table, int i, int j) {
        if (table[i][j] != -1) {
            return table[i][j];
        }
        if (s[i] == '\0') {
            if (p[j] == '\0') {
                table[i][j] = 1;
                return 1;
            }
            else if (p[j] == '*') {
                table[i][j] = is_match(s, p, table, i, j+1);
                return table[i][j];
            }
            else {
                table[i][j] = 0;
                return 0;
            }
        }
        if (make_a_parse(s[i], p[j])) {
            if (p[j] == '*') {
                table[i][j] = is_match(s, p, table, i, j+1) || is_match(s, p, table, i+1, j) || is_match(s, p, table, i+1, j+1);
                return table[i][j];
            }
            else {
                table[i][j] = is_match(s, p, table, i+1, j+1);
                return table[i][j];
            }
        }
        else {
            table[i][j] = 0;
            return 0;
        }
    }
    
    int make_a_parse(const char s, const char p) {
        if (((p == '?'|| s == p) && s != '\0') || p == '*' ) {
            return 1;
        }
        return 0;
    }
};
