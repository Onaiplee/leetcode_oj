
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
    
        while ( (stop = next_break(u_words, start, L)) != size - 1) {
            string line;
            if (start == stop) {
                // only one word, need to be left justified.
                line = left_justify(u_words, start, stop, L);
            }
            else {
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
