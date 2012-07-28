// The gray code is a binary numeral system where two successive values differ in only one bit.
// Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. 
// A gray code sequence /must begin with 0.

// For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

// 00 - 0
// 01 - 1
// 11 - 3
// 10 - 2

/*
 * I will add some comments later
 */

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> seq;
        seq.push_back(0);
        if (n == 0) {
            return seq;
        }
        else {
            seq.push_back(1);
            if (n == 1) {
                return seq;
            }
            for(int i = 1, p = 1; i < n; i++) {
                p = p * 2;
                for (int j = seq.size(); j > 0; j--) {
                    seq.push_back(seq[j-1] + p);
                }
            }
        }
        return seq;
        
    }
};
