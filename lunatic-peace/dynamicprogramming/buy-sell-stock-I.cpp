/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/solution/
121. Best Time to Buy and Sell Stock
If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one.
*/
class Solution {
public:
    int maxProfit(vector<int>& stockPrices) {
        int profit = 0;
        int minimumPrice = INT_MAX;
        /* 
         * for any given day, maximum profit obtainable is - 
         * maximum of(maximum profit obtained till previous day, stock price on that day - minimum stock price so far)
         */
        for(int i = 0; i < stockPrices.size(); i++)
        {
            profit = max(profit, stockPrices[i] - minimumPrice);
            minimumPrice = min(stockPrices[i], minimumPrice);
        }       
        return profit;
    }
    
    int maxProfitBruteForce(vector<int>& stockPrices) {
    int maxprofit = 0;
        for (int i = 0; i < stockPrices.size() - 1; i++) {
            for (int j = i + 1; j <  stockPrices.size(); j++) {
                int profit = stockPrices[j] - stockPrices[i];
                if (profit > maxprofit)
                    maxprofit = profit;
            }
        }
    return maxprofit;
    }
};
