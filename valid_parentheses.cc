// Given a string containing just the characters '(', ')', '{', '}', 
// '[' and ']', determine if the input string is valid.

// The brackets must close in the correct order, "()" and "()[]{}" 
// are all valid but "(]" and "([)]" are not.

/**
 * I will add some comments later.
 */

class Solution {
public:
    bool isValid(string s) {
        int size = s.size();
        stack<char> st;
        for (int i = 0; i < size; i++) {
            if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
                st.push(s[i]);
            }
            else if (s[i] == '}') {
                if (!st.empty() && st.top() == '{') {
                    st.pop();
                }
                else {
                    return false;
                }
            }
            else if (s[i] == ']') {
                if (!st.empty() && st.top() == '[') {
                    st.pop();
                }
                else {
                    return false;
                }
            }
            else if (s[i] == ')') {
                if (!st.empty() && st.top() == '(') {
                    st.pop();
                }
                else {
                    return false;
                }
            }
            else {
                return false;
            }
        }
        if (st.empty()) {
            return true;
        }
        else {
            return false;
        }
    }
};
