// Determine whether an integer is a palindrome. 
// Do this without extra space.

/**
 * I will add some comments later.
 */

// iterative solution
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int divider = 1;
        while (x / divider >= 10) {
            divider *= 10;
        }
        int l = x;
        int u = x;
        while (l && u) {
            if (u / divider != l % 10) {
                return false; 
            }
            l = (l - l % 10) / 10;
            u = u - (divider * (u / divider));
            divider /= 10;
        }
        return true;
    }
};

// recursive solution. but like a shit...
class Solution {
public:
    bool isPalindrome(int x) {
        int i = 10;
        if (x < 0) {
            return false;
        }
        if (x >= 0 && x < 10) {
            return true;
        }
        int divider = 1;
        while (x / divider >= 10) {
            divider *= 10;
        }
        int temp = (x - (divider * (x / divider)) - x % 10) / 10;
        if (x / divider != x % 10) {
            return false;
        }
        else {
            while (temp && temp % 10 == 0) {
                if (x % divider == x % (divider/i)) {
                    temp = temp / 10;
                    i = i * 10;
                }
                else {
                    return false;
                }
                
            }
            return isPalindrome(temp);
        }
    }
};
