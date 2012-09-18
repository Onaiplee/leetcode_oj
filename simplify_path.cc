// Given an absolute path for a file (Unix-style), simplify it.
// 
// For example,
// path = "/home/", => "/home"
// path = "/a/./b/../../c/", => "/c"

/**
 * I will definately simplify this solution later...
 */

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        if (path[0] == '/') {
            st.push(string("/"));
        }
        int i = 0;
        int j = 0;
        string p;
        string parent("..");
        string current(".");
        string root("/");
        string empty("");
        while (i != path.size()) {
            while (i != path.size() && path[i] == '/') {
                i++;
            }
            j = i;
            while (j != path.size() && path[j] != '/') {
                j++;
            }
            p = path.substr(i, j - i);
            if (p == empty) {
                break;
            }
            else if (p == current) {
                if (st.empty()) {
                    st.push(p);
                }
            }
            else if (p == parent) {
                if (st.top() == current) {
                    st.pop();
                    st.push(p);
                }
                else {
                    if (st.top() != root) {
                        st.pop();
                    }
                }
            }
            else {
                st.push(p);
            }
            i = j;
        }
        string result("");
        
        if (st.top() == root) {
            return root;
        }
        
        while (!st.empty()) {
            result = string("/") + st.top() + result;
            st.pop();
        }
        if (result[0] == '/' && result[1] == '/') {
            return result.substr(2, result.size() - 2);
        }
        return  result.substr(1, result.size() - 1);
    }
};
