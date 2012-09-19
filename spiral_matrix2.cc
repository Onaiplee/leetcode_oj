// Given an integer n, generate a square matrix filled with elements 
// from 1 to n2 in spiral order.
// 
// For example,
// Given n = 3,
// 
// You should return the following matrix:
// [
//  [ 1, 2, 3 ],
//  [ 8, 9, 4 ],
//  [ 7, 6, 5 ]
// ]

/**
 * I will add some comments later.
 */

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        if (n == 0) {
            vector<vector<int> >(1, vector<int>());
        }
        vector<vector<int> > matrix(n, vector<int>(n, 0));
        int step = n - 1;
        int row = 0;
        int col = 0;
        int count = 1;
        while (step >= 0)  {
            if (step == 0) {
                matrix[row][col] = count++;
            }
            else {
                // from west to east;
                for (int i = 0; i < step; i++) {
                    matrix[row][col+i] = count++;
                }
                col += step;

                // from east to south;
                for (int i = 0; i < step; i++) {
                    matrix[row+i][col] = count++;
                }
                row += step;

                // from south to west;
                for (int i = 0; i < step; i++) {
                    matrix[row][col-i] = count++;
                }
                col -= step;

                // from west to north;
                for (int i = 0; i < step; i++) {
                    matrix[row-i][col] = count++;
                }
                row -= (step - 1);

                // shift one position to right;
                col++;
            }
            step -= 2;
        }
        return matrix;
    }
};
