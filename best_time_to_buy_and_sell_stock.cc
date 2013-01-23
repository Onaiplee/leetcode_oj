// Say you have an array for which the ith element is the price 
// of a given stock on day i.
// 
// If you were only permitted to complete at most one transaction 
// (ie, buy one and sell one share of the stock), design an algo-
// -rithm to find the maximum profit.

/**
 * I will add some comments later.
 */

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int size = prices.size();
        if (!size) {
            return 0;
        }
        int min = prices[0];
        int max_p = 0;
        for (int i = 1; i < size; i++) {
            if (prices[i] - min > max_p) {
                max_p = prices[i] - min;
            }
            if (prices[i] < min) {
                min = prices[i];
            }
        }  
        return max_p;
    }
};
