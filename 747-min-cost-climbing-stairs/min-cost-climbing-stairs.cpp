class Solution {
public:
      int minCost(int index, vector<int>& cost, vector<int>& dp) {
        if (index >= cost.size())
            return 0;

        if (dp[index] != -1)
            return dp[index];

        int oneStep = cost[index] + minCost(index + 1, cost, dp);
        int twoSteps = cost[index] + minCost(index + 2, cost, dp);

        return dp[index] = min(oneStep, twoSteps);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, -1);
          return min(minCost(0, cost, dp),
                   minCost(1, cost, dp));}
};