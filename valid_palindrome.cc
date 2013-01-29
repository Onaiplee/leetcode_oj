class Solution {
public:
    bool isPalindrome(string s) {
        int size = s.size();
        if (!size) {
            return true;
        }
        int i = 0;
        int j = 0;
        for (; j < size; j++) {
            if (isAlphaNumeric(s[j])) {
                s[i] = s[j];
                if (s[i] > 64 && s[i] < 91) {
                    s[i] += 32;
                }
                i++;
            }
        }
        return is_palindrome(s, 0, i - 1);
    }

    bool isAlphaNumeric(char c) {
        if ((47 < c && c < 58) || (64 < c && c < 91) || (96 < c && c < 123)) {
            return true;
        }
        return false;
    }
    
    bool is_palindrome(string &s, int l, int r) {
        if (r < l) {
            return true;
        }
        int m = (l + r) / 2;
        while (l <= m) {
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};
