// Given an array S of n integers, find three integers in S such that the sum 
// is closest to a given number, target. Return the sum of the three integers. 
// You may assume that each input would have exactly one solution.
// 
//     For example, given array S = {-1 2 1 -4}, and target = 1.
// 
//     The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

/**
 * Please refer to 3sum problem.
 */

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        int min_so_far = 1000;
        int result;
        int temp;
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
                temp = a + b + c - target;
                if (temp < 0) {
                    temp = -temp;
                    k++;
                }
                else {
		    l--;
                }
                if (temp < min_so_far) {
                    min_so_far = temp;
                    result = a + b + c;
                }
            }
            
        }
        return result;
    }
};
