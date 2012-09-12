// Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
//
// For example,
// Given:
// s1 = "aabcc",
// s2 = "dbbca",
// 
// When s3 = "aadbbcbcac", return true.
// When s3 = "aadbbbaccc", return false.

/**
 * I will add some comments later or give an iterative solution.
 */

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size();
        int n2 = s2.size();
        int n3 = s3.size();
        if (!n1 && !n2 && !n3) {
            return true;
        }
        
        if (s1[n1-1] == s2[n2-1]) {
            if (s1[n1-1] == s3[n3-1]) {
                return isInterleave(s1.substr(0, n1-1), s2, s3.substr(0, n3-1)) || isInterleave(s1, s2.substr(0, n2-1), s3.substr(0, n3-1));
            }
            else {
                return false;
            }
        }

        if (n1 && s3[n3-1] == s1[n1-1]) {
            return isInterleave(s1.substr(0, n1-1), s2, s3.substr(0, n3-1));
        }
        else if (n2 && s3[n3-1] == s2[n2-1]) {
            return isInterleave(s1, s2.substr(0, n2-1), s3.substr(0, n3-1));
        }
        else {
            return false;
        } 
    }
};
