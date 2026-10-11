
class Solution {
public:
    int ways(int i, int sum, vector<int>& nums, int target,
             vector<vector<int>>& dp, int offset) {

        if (i == nums.size()) {
            return sum == target ? 1 : 0;
        }

        if (dp[i][sum + offset] != -1) {
            return dp[i][sum + offset];
        }

        int plus = ways(i + 1, sum + nums[i], nums,
                        target, dp, offset);

        int minus = ways(i + 1, sum - nums[i], nums,
                         target, dp, offset);

        return dp[i][sum + offset] = plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int total = 0;
        for (int x : nums) total += x;

        if (abs(target) > total) return 0;

        int offset = total;

        vector<vector<int>> dp(
            nums.size(),
            vector<int>(2 * total + 1, -1)
        );

        return ways(0, 0, nums, target, dp, offset);
    }
};
