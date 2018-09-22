/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

Example 1:

Input: [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
             Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
*/
#define T_COUNT 2
class Solution {
    /* This solution can be extend for k transaction.
    
    */
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0)
            return 0;
        int count = prices.size();
        int maxDiff = 0;
        
        int profit[T_COUNT + 1][ count + 1];
        
        for (int i = 0; i <= T_COUNT; i++)
            profit[i][0] = 0;
        
        for (int j = 0; j <= prices.size(); j++)
            profit[0][j] = 0;
        
        for (int i = 1; i <= T_COUNT; i++) {
            int maxDiff = INT_MIN;
            for (int j = 1; j < prices.size();j++) {
                 maxDiff = max(maxDiff, profit[i - 1][j - 1] - prices[j - 1]); 
                 profit[i][j] = max(profit[i][j - 1], prices[j] + maxDiff);
            }
        }
        return profit[T_COUNT][count-1];
    }
};
