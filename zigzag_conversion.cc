// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
// (you may want to display this pattern in a fixed font for better legibility)
// 
// P   A   H   N
// A P L S I I G
// Y   I   R
// 
// And then read line by line: "PAHNAPLSIIGYIR"
// Write the code that will take a string and make this conversion given a number of rows:
// 
// string convert(string text, int nRows);
// convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

class Solution {
public:
    string convert(string s, int nRows) {
        string empty;
        vector<string> rows(nRows, empty);
        vector<int> indice;
        for (int i = 0; i < nRows; i++) {
            indice.push_back(i);
        }
        for (int i = nRows - 2; i > 0; i--) {
            indice.push_back(i);
        }
        int size = indice.size();
        for (int i = 0; i < s.size(); i++) {
            rows[indice[i % size]].push_back(s[i]);
        }
        string result;
        for (int i = 0; i < nRows; i++) {
            result += rows[i];
        }
        return result;
    }
};
