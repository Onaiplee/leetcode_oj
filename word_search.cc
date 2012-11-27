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

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        vector<vector<char> > mark = board;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                bool ret = search(board, i, j, word);
                if (ret == true) {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool search(vector<vector<char> > &board, int i, int j, string word) {
        vector<bool> row(board[0].size(), false);
        vector<vector<bool> > mark(board.size(), row);
        return dfs(board, mark, 0, word, i, j);
    }
    bool dfs(vector<vector<char> > &board, vector<vector<bool> > &mark, int depth, string word, int i, int j) {
        int  delta_x[4] = {1, -1, 0, 0};
        int  delta_y[4] = {0, 0, 1, -1};
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) {
            if (depth == word.size()) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            if (mark[i][j] == true) {
                return false;
            }
            if (word[depth] == board[i][j]) {
                if (depth == word.size() - 1) {
                    return true;
                }
                mark[i][j] = true;
                for (int k = 0; k < 4; k++) {
                    if (dfs(board, mark, depth+1, word, i+delta_x[k], j+delta_y[k])) {
                        return true;
                    }
                }
                mark[i][j] = false;
                return false;
            }
            else {
                return false;
            }
        }
    }
};

int main() 
{
    vector<vector<char> > board;
    vector<char> r1;
    r1.push_back('A');
    r1.push_back('B');
    r1.push_back('C');
    r1.push_back('E');
    vector<char> r2;
    r2.push_back('S');
    r2.push_back('F');
    r2.push_back('C');
    r2.push_back('S');
    vector<char> r3;
    r3.push_back('A');
    r3.push_back('D');
    r3.push_back('E');
    r3.push_back('E');
    board.push_back(r1);
    board.push_back(r2);
    board.push_back(r3);
    //string word("ABCB");
    //string word("ABCCED");
    string word("SEE");
    Solution s;
    if (s.exist(board, word)) {
        cout << "exsit!" << endl;
    }
    else {
        cout << "doesn't exist!" << endl;
    }
}
