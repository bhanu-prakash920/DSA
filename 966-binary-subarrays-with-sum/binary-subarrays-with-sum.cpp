class Solution {
public:
    int solve(vector<int>& nums, int goal) {
        if (goal < 0)
            return 0;
        int left = 0, right = 0, ans = 0;
        int n = nums.size();
        vector<int> mp(2, 0);
        while (right < n) {
            mp[nums[right]]++;
            while(mp[1] > goal) {
                mp[nums[left]]--;
                left++;
            }
            if (mp[1] <= goal)
                ans += right - left + 1;
            right++;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return solve(nums, goal) - solve(nums, goal - 1);
    }
};