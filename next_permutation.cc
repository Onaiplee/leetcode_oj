// Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
// 
// If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
// 
// The replacement must be in-place, do not allocate extra memory.
// 
// Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
// 1,2,3 → 1,3,2
// 3,2,1 → 1,2,3
// 1,1,5 → 1,5,1

/**
 * I will add some coments later.
 */

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        if (num.size() == 1) {
            return;
        }
        int j = num.size() - 1;
        while (j > 0 && num[j] <= num[j-1]) {
            j--;
        }
        int i = j;
        while (i < num.size() && num[j-1] < num[i]) {
            i++;
        }
        swap(num[i-1], num[j-1]);
        reverse(num, j); 
    }
    
    void reverse(vector<int> &num, int i) {
        int temp;
        int j = num.size() - 1;
        while (i < j) {
            swap(num[i], num[j]);
            i++;
            j--;
        }
    }
    
    void swap(int &a, int &b) {
        int temp;
        temp = a;
        a = b;
        b = temp;
    }
};
