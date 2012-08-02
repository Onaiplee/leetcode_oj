// Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). 
// n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two 
// lines, which together with x-axis forms a container, such that the container contains the most water.

// Note: You may not slant the container.

/*
 * I will add some comments later.
 */

class Solution {
public:
    int maxArea(vector<int> &height) {
        int max = 0;
        int i = 0;
        int j = height.size() - 1;
        int current;
        while (i < j) {
            current = water(height, i, j);
            if (current > max)
                max = current;
            if (height[i] < height[j])
                i++;
            else
                j--;
        }
        return max;
        
    }
    
    int water(vector<int> &height, int i, int j) {
        int a = height[i];
        int b = height[j];
        int min_h = a < b ? a : b;
        return (j - i) * min_h;
    }
};
