class Solution {
public:
    int profit(int i, int bought, vector<int>& prices,
               vector<vector<int>>& dp) {
        if (i == prices.size())
            return 0;
        int pro = 0;
        if (dp[i][bought] != -1)
            return dp[i][bought];
        if (bought) {
            int sell = prices[i] + profit(i + 1, 0, prices, dp);
            int notsell = profit(i + 1,  1, prices, dp);
            pro = max(sell, notsell);
        } else {
            pro = max(profit(i + 1, 0, prices, dp),
                               profit(i + 1, 1, prices, dp) - prices[i]);
        }
        return dp[i][bought] = pro;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return profit(0, 0, prices, dp);
        
    }
};