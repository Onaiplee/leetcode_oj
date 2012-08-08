// Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
// 
// For "(()", the longest valid parentheses substring is "()", which has length = 2.
// 
// Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.

/**
 * I will add some comments later, maybe better solutions.
 */

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> left;
        stack<int> right;
        int i = 0;
        int max = 0;
        int l, r;
        while ((l = find_next(s, i)) >= 0) {
            r = l + 1;
            // expand l and r to maximum
            expand(s, l, r);
            
            // if there is previous result can be merged with the current
            while (!left.empty()) {
                if (l - 1 == right.top()) {
                    // if any, merge.
                    l = left.top();
                    left.pop();
                    right.pop();
                    // need to expand l and r again
                    expand(s, l, r);
                }
                else {
                    break;
                }
            }
            // update the max
            if (r - l + 1 > max) {
                max = r - l + 1;
            }
            
            // push the current l and r to stack
            left.push(l);
            right.push(r);
 
            i = r + 1;
        }
        return max;
    }

private:
    bool is_single(const string &s, int i) {
        return s[i] == '(' && s[i+1] == ')';
    }
 
    int find_next(const string &s, int i) {
        int size = s.size();
        for (; i < size - 1; i++) {
            if (s[i] == '(' && s[i+1] == ')') {
                return i;
            }
        }
        return -1;
    }
    
    bool expand_r(const string &s, int r) {
        int size = s.size();
        if (r + 1 < size - 1 && is_single(s, r+1)) {
            return true;
        }
        return false;
    }
    
    bool expand_l_r(const string &s, int l, int r) {
        int size = s.size();
        if (l > 0 && r < size - 1 && s[l-1] == '(' && s[r+1] == ')') {
            return true;
        }
        return false;
    }
    
    void expand(const string &s, int &l, int &r) {
        while (1) {
            if (expand_r(s, r)) {
                r = r + 2;
            }
            else if (expand_l_r(s, l, r)) {
                l = l - 1;
                r = r + 1;
            }
            else {
                break;
            }
        }
    }
};
