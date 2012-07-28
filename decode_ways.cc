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
 * Firstly, let us think it small. Suppose we have a string "218", how can we solve it by hand? 
 * Notice the string is ending with "18", so it can be splitted as either "2|18" or "21|8". If we
 * can know the number of ways that "2" and "21" can be decoded, it's done. 
 *
 *              solution("218")  = solution("2") + solution("21")
 * 
 * The solution of substring "2" and "21" are trivial, respectively, 1 and 2. So the final solution
 * is 3. So if we have a string "xxxxxxxx18", the solution is easy as long as we know the solution of
 * "xxxxxxxx" and "xxxxxxxx1". Now it's the time to see the general situation:
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
 * Note: this is only good for A[2..N], where A is 0 index. So we need to give answer for A[0] and A[1]
 * So now we know how to solve this problem. The algorithm below has \Theta(n) time complexity and \Theta(n) 
 * in space.Enjoy it.
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

/* 
 * Further optimization:
 *
 * Notice that calculating A[i] only depend on A[i-1] and A[i-2] , so we can just need to have two variables,
 * and update them after each iteration. This can reduce the space complexity to \Theta(1).
 * Here it is:
 */


