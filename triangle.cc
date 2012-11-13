// Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
// 
// For example, given the following triangle
// [
//      [2],
//     [3,4],
//    [6,5,7],
//   [4,1,8,3]
// ]
// The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
// 
// Note:
// Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.


/**
 * The first one solution the trivial DP without using memoization. The second one is DP from bottom to top with complexity O(n).
 */

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int min = INT_MAX;
        int size = triangle.size();
        for (int i = 0; i < triangle[size-1].size(); i++) {
            int m = minimum(triangle, size - 1, i);
            if (m < min) {
                min = m;
            }
        }
        return min;
    }
    
    int minimum(vector<vector<int> > &triangle, int row, int index) {
        cout << triangle[row][index] << endl;
        if (row == 0) {
            return triangle[0][0];
        }
        else {
            if (index == 0) {
                return minimum(triangle, row - 1, index);
            }
            else if (index == triangle[row].size() - 1) {
                return minimum(triangle, row - 1, index - 1);
            }
            else {
                return min(minimum(triangle, row - 1, index), minimum(triangle, row - 1, index - 1));
            }
        }
    }
};

/**
 * Second solution.
 */

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int size = triangle.size();
        vector<int> table(size, 0);
        table[0] = triangle[0][0];
        for (int i = 1; i < size; i++) {
            int temp = table[0];
            for (int j = 0; j < triangle[i].size(); j++) {
                int current = triangle[i][j];  
                if (j == 0) {
                    table[j] = temp + current;
                }
                else if (j == triangle[i].size() - 1) {
                    table[j] = temp + current;
                }
                else {
                    temp = min(temp, table[j]) + current;
                    swap(temp, table[j]);
                }
            }
        }
        int min = INT_MAX;
        for (int i = 0; i < table.size(); i++) {
            if (table[i] < min) {
                min = table[i];
            }
        }
        return min;
    }
  
    void swap(int &a, int &b) {
        int temp;
        temp = a;
        a = b;
        b = temp;
    }
};
