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
 * This is the refactored one, original messed up solution has been put
 * in alternatives/.
 */

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> result;

        // convert to one word per entry without any spaces.
        vector<string> u_words = to_words(words);
        int stop = -1;
        int start = 0;
        int size = u_words.size();
    
        // if no word, just add L spaces.
        if (size == 0) {
            result.push_back(string(L, ' '));
            return result;
        }
        
        // Find the next line break position ^_^
        while ( (stop = next_break(u_words, start, L)) != size - 1) {
            string line;
            if (start == stop) {
                // only one word, need to be left justified.
                line = left_justify(u_words, start, stop, L);
            }
            else {
                // otherwise do left right justification
                line = lr_justify(u_words, start, stop, L);
            }
            result.push_back(line);
            start = stop + 1;
        }
    
        // last line need to be left justified
        string line = left_justify(u_words, start, stop, L);
        result.push_back(line);
        return result;
    }

    vector<string> to_words(vector<string> &words) {
        vector<string> result;
        for (int i = 0; i < words.size(); i++) {
            int size = words[i].size();
            for (int j = 0; j < size; ) {
                while (j < size && words[i][j] == ' ') {
                    j++;
                }
                if (j == size) {
                    break;
                }
                int s = j;
                while (j < size && words[i][j] != ' ') {
                    j++;
                }
                result.push_back(words[i].substr(s, j - s));
            }
        }
        return result;
    }

    int next_break(vector<string> words, int start, int L) {
        int length = 0;
        int size = words.size();
        for (int i = start; i < size; i++) {
            length += (words[i].size() + 1);
            if (length - 1 > L) {
                return i - 1;
            }
        }
        return size - 1;
    }
    
    string left_justify(vector<string> &words, int l, int u, int L) {
        string line;
        int length = 0;
        for (int i = l; i < u; i++) {
            line += words[i];
            line.push_back(' ');
            length += (words[i].size() + 1);
        }
        line += words[u];
        length += words[u].size();
        padding_zeroes(line, L - length);
        return line;
    }

    string lr_justify(vector<string> &words, int l, int u, int L) {
        int raw = 0;
        string line;
        for (int i = l; i <= u; i++) {
            raw += words[i].size();
        }
        int spaces = L - raw;
        int intervals = u - l;
        int avg = spaces / intervals;
        int inc = spaces % intervals;
        for (int i = l; i < u; i++) {
            line += words[i];
            padding_zeroes(line, avg);
            if (inc > 0) {
                padding_zeroes(line, 1);
                inc--;
            }
        }
        line += words[u];
        return line;
    }
    
    void padding_zeroes(string &s, int n) {
        for (int i = 0; i < n; i++) {
            s.push_back(' ');
        }
    }
};
