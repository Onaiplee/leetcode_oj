// Say you have an array for which the ith element is the price of a given stock on day i.

// Design an algorithm to find the maximum profit. You may complete as many transactions 
// as you like (ie, buy one and sell one share of the stock multiple times). However, you 
// may not engage in multiple transactions at the same time (ie, you must sell the stock 
// before you buy again).

/**
 * This solution is not easy to verify... I will modify it and add comments later.
 */

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int size = prices.size();
        if (!size) {
            return 0;
        }
        int max_p = 0;
        int p = 0;
        while (p < size - 1) {
            int min = prices[p];
            int profit = 0;
            int i;
            for (i = p + 1; i < size; i++) {
                if (prices[i] < prices[i-1]) {
                    break;
                }
                if (prices[i] - min > profit) {
                    profit = prices[i] - min;
                }
                if (prices[i] < min) {
                    min = prices[i];
                }
            }
            p = i;
            max_p += profit;
        }
        return max_p;
    }
};
