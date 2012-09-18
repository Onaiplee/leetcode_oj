// Given a m x n matrix, if an element is 0, set its entire row and column 
// to 0. Do it in place.
// 
// Follow up:
// Did you use extra space?
// A straight forward solution using O(mn) space is probably a bad idea.
// A simple improvement uses O(m + n) space, but still not the best solution.
// Could you devise a constant space solution?

/**
 * I will come up with a constant space solution later...
 */

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        vector<int> row(matrix.size(), 0);
        vector<int> col(matrix[0].size(), 0);
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == 0) {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }
        
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (row[i] == 1 || col[j] == 1) {
                    matrix[i][j] = 0;
                }
            }
        }
        
    }
};
