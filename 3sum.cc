// Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
// Find all unique triplets in the array which gives the sum of zero.
// 
// Note:
// Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
// The solution set must not contain duplicate triplets.
//     For example, given array S = {-1 0 1 2 -1 -4},
// 
//     A solution set is:
//     (-1, 0, 1)
//     (-1, -1, 2)

/**
 * I will add some comments later.
 */

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > result;
        set<vector<int> > array_set;
        sort(num.begin(), num.end());
        int length = num.size();
        int l;
        int k;
        int a, b, c;
        for (int i = 0; i < length - 2; i++) {
            a = num[i];
            k = i + 1;
            l = length - 1;
            while (k < l) {
                b = num[k];
                c = num[l];
                vector<int> s;
                if (a + b + c == 0) {
                    s.push_back(a);
                    s.push_back(b);
                    s.push_back(c);
                    if (array_set.insert(s).second) {
                        result.push_back(s);
                    }
                    k++;    
                    l--;
                }
                else if (a + b + c < 0) {
                    k++;
                }
                else {
                    l--;
                }
            }
            
        }
        return result;
    }
};
