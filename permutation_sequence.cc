// he set [1,2,3,…,n] contains a total of n! unique permutations.
// 
// By listing and labeling all of the permutations in order,
// We get the following sequence (ie, for n = 3):
// 
// "123"
// "132"
// "213"
// "231"
// "312"
// "321"
// Given n and k, return the kth permutation sequence.

/**
 * I will add some comments later.
 */

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> num;
        for (int i = 1; i <= n; i++) {
            num.push_back(i);
        }
        k--;
        int p = 0;
        int f = fact(n-1-p);
        while (k != 0) {
            int r;
            int i = k / f;
            swap(num[p], num[p+i]);
            k = k - i * f;
            while(i > 1) {
                swap(num[p+i], num[p+i-1]);
                i--;
            }
            f = f / (n-1-p);
            p++;
        }

        ostringstream os(ostringstream::out);
        for (int i = 0; i < num.size(); i++) {
            os << num[i];
        }
        return os.str();
    }
    
    int fact(int n) {
        int ret = 1;
        for (int i = 1; i <= n; i++) {
            ret *= i;
        }
        return ret;
    }
    
    void swap(int &a, int &b) {
        int temp;
        temp = a;
        a = b;
        b = temp;
    }
};
