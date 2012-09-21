#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
vector<string> fullJustify(vector<string> &words, int L) {
    vector<string> result;
    int stop = -1;
    int start = 0;
    int size = words.size();
    while ( (stop = next_break(words, start, L)) != size - 1) {
        string line;
        if (start == stop) {
            // only one words, left justify
            line = left_justify(words, start, stop, L);
        }
        else {
            line = lr_justify(words, start, stop, L);
        }
        result.push_back(line);
        start = stop + 1;
    }

    // last line
    string line = left_justify(words, start, stop, L);
    result.push_back(line);
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

int main()
{
    string w1("This");
    string w2("is");
    string w3("an");
    string w4("example");
    string w5("of");
    string w6("text");
    string w7("justification.");
    vector<string> words;
    words.push_back(w1); 
    words.push_back(w2); 
    words.push_back(w3); 
    words.push_back(w4); 
    words.push_back(w5); 
    words.push_back(w6); 
    words.push_back(w7); 
    Solution s;
    vector<string> result = s.fullJustify(words, 16);
 
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
}
