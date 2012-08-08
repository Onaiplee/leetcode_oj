// Given a string, find the length of the longest substring without repeating characters. 
// For example, the longest substring without repeating letters for "abcabcbb" is "abc", 
// which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.

/**
 * The key to this problem is how to keep loop invariant.
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) {
            return 0;
        }

        int table[26];
        for (int i = 0; i < 26; i++) {
            table[i] = -1;
        }

        // initial condition s[0..(1-1)] is the longest sub-string ending at 1.
        int i = 0;
        int max = 1;
        table[to_i(s[0])] = 0;
        int j = 1;
        while (j < s.size()) {
            // look invariant: s[i..j-1] is the longest sub-string ending at j. 
            if (table[to_i(s[j])] != -1) {
                for (int k = i; k < table[to_i(s[j])]; k++) {
                    table[to_i(s[k])] = -1;
                }
                i = table[to_i(s[j])] + 1;
                table[to_i(s[j])] = j;
            }
            else {
                table[to_i(s[j])] = j;
                if (j-i+1 > max) {
                    max = j-i+1;
                }
            }
            j++;
        }
        // j = N, so s[i..N-1] is the longest sub-string ending at N-1.
        // now we have iterate all the sub-strings ending at 0 to N-1,
        // so we are very confident that the algorithms is correct!
        return max;
    }
    
    int to_i(char c) {
        return c - 'a';
    }
};
