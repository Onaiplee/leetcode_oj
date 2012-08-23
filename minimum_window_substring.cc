// Given a string S and a string T, find the minimum window 
// in S which will contain all the characters in T in complexity 
// O(n).
// 
// For example,
// S = "ADOBECODEBANC"
// T = "ABC"
// Minimum window is "BANC".
// 
// Note:
// If there is no such window in S that covers all characters in T, 
// return the emtpy string "".
// 
// If there are multiple such windows, you are guaranteed that there 
// will always be only one unique minimum window in S.

/**
 * I will add some comments later.
 */

class Solution {
public:
    string minWindow(string S, string T) {
        int table[256];
        int st[256];
        int min = INT_MAX;
        int min_l = 0;
        int min_u = 0;
        for (int i = 0; i < 256; i++) {
            table[i] = 0;
            st[i] = 0;
        }
        for (int i = 0; i < T.size(); i++) {
            table[T[i]] = 0;
            st[T[i]]++;
        }
        int ct = 0;
        int i = 0;
        int j = 0;
        
        while (j < S.size()) {
            for (; j < S.size(); j++) {
                if (st[S[j]] > 0) {
                    if (table[S[j]] < st[S[j]]) {
                        table[S[j]]++;
                        ct++;
                        if (ct == T.size()) {
                            break;
                        }
                    }
                    else {
                        table[S[j]]++;
                    }
                }
            }
    
            while (ct == T.size()) {
                if (st[S[i]] > 0) {
                    if (table[S[i]] > st[S[i]]) {
                        table[S[i]]--;
                        i++;
                    }
                    else {
                        // assert(table[S[i]] == st[S[i]])
                        if (j - i + 1 < min) {
                            min = j - i + 1;
                            min_l = i;
                            min_u = j;
                        }
                        ct--;
                        table[S[i]]--;
                        i++;
                    }
                }
                else {
                    i++;
                }
            }
            j++;
        }


        if (min == INT_MAX) {
            return string("");
        } 
        
        return S.substr(min_l, min_u - min_l + 1);

    }
};
