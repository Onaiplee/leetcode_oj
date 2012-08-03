// Given an integer, convert it to a roman numeral.
// 
// Input is guaranteed to be within the range from 1 to 3999.

/**
 * This is a WRONG answer. The only reason that I put it here is to show a DP
 * approach to get the minimum length roman integer. 
 */

class Solution {
public:
    string intToRoman(int num) {
        int min[4000];
        int pre[4000]; 
        int max = ~0 ^ (1 << 31);

        for (int i = 0; i <= num; i++) {
            min[i] = max;
        }

        int value[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        char const *s[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
        vector<string> symbol;
        for (int i = 0; i < 13; i++) {
            symbol.push_back(s[i]);
        }

        for (int i = 0; i < 13; i++) {
            if (num >= value[i]) {
                min[value[i]] = 1;
                pre[value[i]] = i;
            }
        }

        for (int i = 1; i <= num; i++) {
            for (int j = 0; j < 13; j++) {
                if (i+value[j] <= num && symbol[j].size() + min[i] < min[i+value[j]]) {
                    min[i+value[j]] = symbol[j].size() + min[i];
                    pre[i+value[j]] = j;
                }
            }
        }
        
        ostringstream os(ostringstream::out);
        int p = num;
        while (p > 0) {
                os << symbol[pre[p]];
                p = p - value[pre[p]];
        }
        return os.str();
    }
};
