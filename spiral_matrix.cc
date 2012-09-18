// Given a matrix of m x n elements (m rows, n columns), 
// return all elements of the matrix in spiral order.
// 
// For example,
// Given the following matrix:
// 
// [
//  [ 1, 2, 3 ],
//  [ 4, 5, 6 ],
//  [ 7, 8, 9 ]
// ]
// You should return [1,2,3,6,9,8,7,4,5].

/**
 * I will add some comments later.
 */

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> result;
        if (matrix.size()) {
            spiral(matrix, result, 0, 0, matrix.size(), matrix[0].size());
        }
        return result;
    }
     
    void spiral(vector<vector<int> > &matrix, vector<int> &result, int x, int y, int m, int n) {
        if (!m || !n) {
            return;
        }
        else if (m == 1 || n == 1) {
            if (m == 1) {
                for (int i = 0; i < n; i++) {
                    result.push_back(matrix[x][y+i]);
                }
            }
            else {
                for (int i = 0; i < m; i++) {
                    result.push_back(matrix[x+i][y]);
                }
            }
            return;
        }
        else {
            // from west to east
            for (int i = 0; i < n - 1; i++) {
                result.push_back(matrix[x][y+i]);
            }
            
            y = y + n - 1;
            // from east to south
            for (int i = 0; i < m - 1; i++) {
                result.push_back(matrix[x+i][y]);
            }
            
            x = x + m - 1;
            // from south to east
            for (int i = 0; i < n - 1; i++) {
                result.push_back(matrix[x][y-i]);
            }
            
            y = y - n + 1;
            // from east to north
            for (int i = 0; i < m - 1; i++) {
                result.push_back(matrix[x-i][y]);
            }
            
            x = x - (m - 2);
            y = y + 1;
            spiral(matrix, result, x, y, m - 2, n - 2);
        }
    }
};
