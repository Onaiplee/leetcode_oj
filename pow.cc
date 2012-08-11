// Implement pow(x, n).

/**
 * I got a runtime error during judge large section but I don't 
 * know why...
 */

class Solution {
public:
    double pow(double x, int n) {
        double m;
        if (n < 0) {
            if (n == INT_MIN) {
                return 1 / (x * pow(x, -(n+1)));
            }
            return 1 / pow(x, -n);
        }
        if (n == 0) {
            return 1;
        }
        if (n % 2) {
            return x * pow(x, n-1);
        }
        else {
            // Why not return pow(x, n/2) * pow(x, n/2)? ^_^
            m = pow(x, n/2);
            return m * m;
        }
    }
};
