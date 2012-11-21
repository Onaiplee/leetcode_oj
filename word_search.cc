// Given a 2D board and a word, find if the word exists in the grid.
// 
// The word can be constructed from letters of sequentially adjacent 
// cell, where "adjacent" cells are those horizontally or vertically 
// neighboring. The same letter cell may not be used more than once.
// 
// For example,
// Given board =
// 
// [
//   ["ABCE"],
//   ["SFCS"],
//   ["ADEE"]
// ]
// word = "ABCCED", -> returns true,
// word = "SEE", -> returns true,
// word = "ABCB", -> returns false.

/**
 * Incomplete solution yet!!
 */

class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        vector<vector<char> > mark = board;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                search(board, i, j, word)
            }
        }
        dfs();
    }
    
    bool search(vector<vector<char> > &board, int i, int j, string word) {
        dfs(board);
    }
    void dfs(vector<vector<char> > &board, vector<vector<char> > &mark, int depth, string word) {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) {
            if (depth == word.size()) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            if (word[depth] == board[i][j]) {
                if (depth == word.size() - 1) {
                    return true;
                }
                mark[i][j] = true;
                if (dfs(board, i+1, j, word) || dfs(board, i-1, j, word) || dfs(board, i, j+1, word) || dfs(board, i, j-1, word)) {
                    return true;
                }
                else {
                    mark[i][j] = false;
                    return false;
                }
            }
            else {
                return false;
            }
        }
    }
};
