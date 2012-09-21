// Given an array of words and a length L, format the text such that each 
// line has exactly L characters and is fully (left and right) justified.
// 
// You should pack your words in a greedy approach; that is, pack as many 
// words as you can in each line. Pad extra spaces ' ' when necessary so that 
// each line has exactly L characters.
// 
// Extra spaces between words should be distributed as evenly as possible. 
// If the number of spaces on a line do not divide evenly between words, the 
// empty slots on the left will be assigned more spaces than the slots on 
// the right.
// 
// For the last line of text, it should be left justified and no extra space 
// is inserted between words.
// 
// For example,
// words: ["This", "is", "an", "example", "of", "text", "justification."]
// L: 16.

// Return the formatted lines as:
// [
//    "This    is    an",
//    "example  of text",
//    "justification.  "
// ]
// Note: Each word is guaranteed not to exceed L in length.

/**
 * This solution definitely need refactoring...
 */

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> result;
        int size = words.size();
        vector<string> u_words;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < words[i].size(); ) {
                while (j < words[i].size() && words[i][j] == ' ') {
                    j++;
                }
                if (j == words[i].size()) {
                    break;
                }
                int s = j;
                while (j < words[i].size() && words[i][j] != ' ') {
                    j++;
                }
                u_words.push_back(words[i].substr(s, j - s)); 
            }
        }
        if (u_words.size() == 0) {
            result.push_back(string(L, ' '));
            return result;
        }
        int l = 0;
        int u = 0;
        size = u_words.size();
        while (u < size) {
            int length = 0;
            int raw = 0;
            for (; u < size; u++) {
                length += u_words[u].size() + 1;
                raw += u_words[u].size();
                if (length - 1 > L) {
                    raw = raw - u_words[u].size();
                    break;
                }
            }

            string line;

            if (u == size) {
                for (int i = l; i < u - 1; i++) {
                    line += u_words[i];
                    line.push_back(' ');
                }
                line += u_words[u-1];
                padding_zeroes(line, L - length + 1);
                result.push_back(line);
                return result;
            }

            // words[l..u-1] is the words that need to fill in the line
            int spaces = L - raw;
            int word_count = u - l; 
            int intervals = word_count - 1;
            int avg = spaces;
            int remains = 0;
            if (word_count > 1) {
                avg = spaces / intervals;
                remains = spaces % intervals;
                for (int i = l; i < u - 1; i++) {
                    line += u_words[i];
                    if (remains > 0) {
                        padding_zeroes(line, avg + 1);
                        remains--;
                    }
                    else {
                        padding_zeroes(line, avg);
                    }
                }
                line += u_words[u-1];
            }
            else {
                line += u_words[l];
                padding_zeroes(line, spaces);
            }
            result.push_back(line);
            l = u;
        }
        return result;
    }


    void padding_zeroes(string &s, int n) {
        while (n-- > 0) {
            s.push_back(' ');
        }
    }
};
