// Problem: 
// A message containing letters from A-Z is being encoded to numbers using the following mapping:
// 
// 'A' -> 1
// 'B' -> 2
// ...
// 'Z' -> 26

// Given an encoded message containing digits, determine the total number of ways to decode it.

// For example,
// Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

// The number of ways decoding "12" is 2.



/* 
 * This is a typical dynamic programming problem. This problem can be solved following PACMAN pattern...
 * Assume a PACMAN can solve a sub-problem very well, you just use this pacman to solve the
 * a bigger problem (to make a bigger PACMAN ^_^). And when the PACMAN grows, you are done done. 
 * 
 * Assume S is the string that need to be decoded, with length N.
 * Create A[0..N-1], Let A[i] is the number of ways the sub-string S[0..i] can be decoded.
 * So if you are at i, you want to know A[i], and there are two PACMANs have solved A[i-1] and
 * A[i-2]. The only thing you need to do is how to use A[i-1] and A[i-2] to calculate A[i].
 * Here it is.
 * Let v = S[i-1] * 10 + S[i]
 *
 *          /   0,               v = 0 or ( 27 < v < 99 and v mod 10 = 0) 
 *         /
 * A[i] = -     A[i-1],          1 < v < 9 or (27 < v < 99 and v mod 10 <> 0)            
 *         \  
 *          \   A[i-2],          v = 10 or v = 20
 *           \
 *            \ A[i-1] + A[i-2], otherwise
 *
 * 
 * Note: this is only good for A[2..N], if A is 0 index. So we need to give answer for A[0] and A[1]
 * So now we know how to solve this problem. Enjoy it.
 */


class Solution {
public:
    int numDecodings(string s) {
        int length = s.size();
        vector<int> A;
        A.reserve(length);
        
        if (length == 0) {
            return 0;
        }
        else {
            // Calculate A[0] here
            if (length == 1) {
                return A[0];
            }
            // Calculate A[1] here
            for (int i = 2; i < s.size(); i++) {
                // Calculate A[i] such that i > 1
            }
        }
        
        return A[length-1];
    }
};
