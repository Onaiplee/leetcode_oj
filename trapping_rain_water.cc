// Given n non-negative integers representing an elevation map where 
// the width of each bar is 1, compute how much water it is able to 
// trap after raining.
// 
// For example, 
// Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

/**
 * I spent 3 hours to get the OJ passed... Don't feel frustrated if 
 * spent a longer time than you expected...
 *
 * I will add some comments later.
 */

class Solution {
public:
    int trap(int A[], int n) {
        stack<int> height;
        stack<int> index;
        height.push(INT_MAX);
        index.push(-1);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (A[i] < height.top()) {
                height.push(A[i]);
                index.push(i);
            }
            else {
                while (height.top() <= A[i]) {
                    int low = height.top();
                    height.pop();
                    index.pop();
                    int high = min(height.top(), A[i]);
                    if (index.top() != -1) {
                        sum += (high - low) * (i - index.top() - 1);
                    }
                }
                if (A[i] < height.top()) {
                    height.push(A[i]);
                    index.push(i);
                }
            }
        }
        return sum;
    }
};

