class Solution {
public:
    int solve(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int ans = 0;
        int n = nums.size();
        unordered_map<int, int> mp;
        while (right < n) {
            mp[nums[right]]++;
            while (mp.size() > k) {
                mp[nums[left]]--;
                if(mp[nums[left]] == 0){
                    mp.erase(nums[left]);
                }
                left++;
            }
            ans += right - left + 1;
            right++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums,k) - solve(nums,k - 1);
    }
};