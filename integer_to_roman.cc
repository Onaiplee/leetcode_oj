// Given an integer, convert it to a roman numeral.
//
// Input is guaranteed to be within the range from 1 to 3999.

/**
 * I will add some comments later. I put a wrong answer to wrong_answer/. That one
 * use DP approach to get minimum result. But actually we should use greedy approach
 * like this. The reason? The human are more comfortable with greedy... ^_^
 */

class Solution {
public:
    string intToRoman(int num) {
        int value[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        char const *symbol[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
        ostringstream os(ostringstream::out);
        while (num != 0) {
            for (int i = 12; i >= 0; i--) {
                if (num >= value[i]) {
                    os << symbol[i];
                    num = num - value[i];
                    break;
                }
            }
        }
        return os.str();
    }
};
