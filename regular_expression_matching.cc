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
 * solve it. I will add a memoization solution to pass 
 * the large test later. 
 * 
 * There is error in small test, say, "." matches any
 * charactor excluding empty string.
 */ 

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if (*p == '\0' && *s == '\0') {
            return true;
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
        if (*p == '.' || *p == *s) {
            return true;
        }
        return false;
    }
};
