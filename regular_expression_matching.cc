// Implement regular expression matching with support for '.' and '*'.
// 
// '.' Matches any single character.
// '*' Matches zero or more of the preceding element.
// 
// The matching should cover the entire input string (not partial).
// 
// The function prototype should be:
// bool isMatch(const char *s, const char *p)

// Some examples:
// isMatch("aa","a") → false
// isMatch("aa","aa") → true
// isMatch("aaa","aa") → false
// isMatch("aa", "a*") → true
// isMatch("aa", ".*") → true
// isMatch("ab", ".*") → true
// isMatch("aab", "c*a*b") → true

/** 
 * Regexp problem can be solved by construct automata. 
 * But that requires more knowledge. Here using DP to
 * solve it. I also give a memoization DP version to 
 * pass the large test.
 */ 

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if (*p == '\0') {
            if (*s == '\0') {
                return true;
            }
            else {
                return false;
            }
        }
       
        if (p[1] == '*') {
            if (parse_one(s, p)) {
                return isMatch(s+1, p+2) || isMatch(s+1, p) || isMatch(s, p+2);
            }
            else {
                return isMatch(s, p+2);
            }
        }
        else {
            if (parse_one(s, p)){
                return isMatch(s+1, p+1);
            }
            else {
                return false;
            }
        }
    }

    bool parse_one(const char *s, const char *p) {
        if (*s != '\0' && (*p == '.' || *p == *s)) {
            return true;
        }
        return false;
    }
};

/**
 * The following is DP with memoization.
 */

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        vector<vector<int> > dict(strlen(s) + 1, vector<int>(strlen(p) + 1, -1));
        return is_match(s, p, 0, 0, dict) == 1? true : false;
    }
    int is_match(const char *s, const char *p, int si, int pi, vector<vector<int> > &dict) {
        if (dict[si][pi] != -1) {
            return dict[si][pi];
        }

        if (p[pi] == '\0') {
            if (s[si] == '\0')  {
                dict[si][pi] = 1;
                return 1;
            }
            else {
                dict[si][pi] = 0;
                return 0;
            }
        }
       
        if (p[pi+1] == '*') {
            if (parse_one(s[si], p[pi])) {
                dict[si][pi] = is_match(s, p, si+1, pi+2, dict) || is_match(s, p, si+1, pi, dict) || is_match(s, p, si, pi+2, dict);
                return dict[si][pi];
            }
            else {
                dict[si][pi] = is_match(s, p, si, pi+2, dict);
                return dict[si][pi];
            }
        }
        else {
            if (parse_one(s[si], p[pi])){
                dict[si][pi] = is_match(s, p, si+1, pi+1, dict);
                return dict[si][pi];
            }
            else {
                dict[si][pi] = 0;
                return dict[si][pi];
            }
        }
    }

    bool parse_one(const char s, const char p) {
        if (s != '\0' && (p == '.' || p == s)) {
            return true;
        }
        return false;
    }
};
