// Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest 
// rectangle in the histogram.

// For example,
// Given height = [2,1,5,6,2,3],
// return 10.

/**
 * I will add some comments later.
 */

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        stack<int> idx;
        stack<int> ht;
        int max = 0;
        int last_pop;
        int size = height.size();
        if (size == 0) {
            return 0;
        }
        idx.push(0);
        ht.push(height[0]);
        for (int i = 1; i < size; i++) {
            int temp;
            if (height[i] > height[i-1]) {
                idx.push(i);
                ht.push(height[i]);
            }
            if (height[i] < height[i-1]) {
                while(!ht.empty() && ht.top() > height[i]) {
                    temp = (i - idx.top()) * ht.top();
                    if (temp > max) {
                        max = temp;
                    }
                    last_pop = idx.top();
                    idx.pop();
                    ht.pop();
                }
                idx.push(last_pop);
                ht.push(height[i]);
            }
        }
        while(!ht.empty()) {
            int temp;
            temp = (size - idx.top()) * ht.top();
            if (temp > max) {
                max = temp;
            }
            idx.pop();
            ht.pop();
        }
        return max;
    }
};
