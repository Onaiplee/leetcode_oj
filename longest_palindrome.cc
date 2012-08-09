// Given a string S, find the longest palindromic substring in S. 
// You may assume that the maximum length of S is 1000, and there 
// exists one unique longest palindromic substring.

/**
 * This is a direct algorithm that take O(n^2) time. There is more
 * tricky algorithms. I will update it and put in alternatives/.
 */

class Solution {
public:
    string longestPalindrome(string s) {
        int max = 0;
        int pos = 0;
        int npos = 0;
        for (int i = 0; i < s.size(); i++) {
            int l, u;
            int length;
            // if the center is at i AND j.
            if (i < s.size() - 1 && s[i] == s[i+1]) {
                l = i;
                u = i+1;
                length = expand2max(s, l, u);
                if (length > max) {
                    max = length;
                    pos = l;
                    npos = length;
                }
            }
            // if the center is at i.
            l = u = i;
            length = expand2max(s, l, u);
            if (length > max) {
                max = length;
                pos = l;
                npos = length;
            }
        }
        return s.substr(pos, npos);
    }

    int expand2max(string &s, int &l, int &u) {
        while (l > 0 && u < s.size() - 1) {
            l--;
            u++;
            if (s[l] != s[u]) {
                l++;
                u--;
                break;
            }    
        }
        return u-l+1;
    }
};
