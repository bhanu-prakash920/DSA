#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int solve(int index, int end, vector<int>& nums, vector<int>& dp) {
        if (index > end)
            return 0;

        if (index == end)
            return nums[index];

        if (dp[index] != -1)
            return dp[index];

        int skip = solve(index + 1, end, nums, dp);

        int take = nums[index] + solve(index + 2, end, nums, dp);

        return dp[index] = max(take, skip);
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp1(n + 1, -1);
        vector<int> dp2(n + 1, -1);
        if (n == 1)
            return nums[0];
        int s1 = solve(0, n - 2, nums, dp1);
        int s2 = solve(1, n - 1, nums, dp2);
        return max(s1, s2);
    }
};
