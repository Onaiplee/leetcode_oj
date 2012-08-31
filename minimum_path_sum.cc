// Given a m x n grid filled with non-negative numbers, find a path 
// from top left to bottom right which minimizes the sum of all 
// numbers along its path.
// 
// Note: You can only move either down or right at any point in time.

/**
 * This is a typical DP problem which can be solved by memoization.
 */

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        vector<vector<int> > sum = grid;
        for (int i = 0; i < sum.size(); i++) {
            for (int j = 0; j < sum[i].size(); j++) {
                sum[i][j] = -1;
            }
        }
        return minPath(grid.size() - 1, grid[0].size() - 1, grid, sum);
    }

    int minPath(int m, int n, vector<vector<int> > &grid, vector<vector<int> > &t) {
        int temp;
        if (m == 0 && n == 0) {
            return grid[0][0];
        }
        
        if (t[m][n] != -1) {
            return t[m][n];
        }
        else {
            if (m == 0 || n == 0) {
                if (m != 0) {
                    t[m][n] = grid[m][n] + minPath(m - 1, n, grid, t);
                }
                else {
                    t[m][n] = grid[m][n] + minPath(m, n - 1, grid, t);
                }
            }
            else {
                t[m][n] = grid[m][n] + min(minPath(m, n-1, grid, t), minPath(m-1, n, grid, t));
            }
            return t[m][n];
        }
    }
   
    int min(int a, int b) {
        return a < b? a : b;
    }
};
