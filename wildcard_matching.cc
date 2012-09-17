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
 * I will add memoization later.
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
