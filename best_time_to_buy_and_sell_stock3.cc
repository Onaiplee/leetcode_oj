// Say you have an array for which the ith element is the price of a given stock on day i.
// 
// Design an algorithm to find the maximum profit. You may complete at most two transactions.
// 
// Note:
// You may not engage in multiple transactions at the same time (ie, you must sell the stock 
// before you buy again).

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
        vector<int> lp(size, 0);
        vector<int> rp(size, 0);
        int min = prices[0];
        int profit = 0;
        for (int i = 1; i < size; i++) {
            if (prices[i] - min > profit) {
                profit = prices[i] - min;
            }
            if (prices[i] < min) {
                min = prices[i];
            }
            lp[i] = profit;
        }
        int max = prices[size - 1];
        profit = 0;
        for (int i = size - 2; i >= 0; i--) {
            if (max - prices[i] > profit) {
                profit = max - prices[i];
            }
            if (prices[i] > max) {
                max = prices[i];
            }
            rp[i] = profit;
        }
        int max_profit = rp[0];
        for (int i = 0; i < size - 1; i++) {
            int m = lp[i] + rp[i+1];
            if (m > max_profit) {
                max_profit = m;
            }
        }
        return max_profit;
    }
};
