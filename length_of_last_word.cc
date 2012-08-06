// Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
// 
// If the last word does not exist, return 0.
// 
// Note: A word is defined as a character sequence consists of non-space characters only.
// 
// For example, 
// Given s = "Hello World",
// return 5.

/**
 * I will add some comments later.
 */

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int length = 0;
        while (*s != '\0') {
            if (*s == ' ') {
                s++;
            }
            else {
                length = 0;
                while ( *s != ' ' && *s != '\0') {
                    length++;
                    s++;
                }
            }
        }
        return length;
    }
};
