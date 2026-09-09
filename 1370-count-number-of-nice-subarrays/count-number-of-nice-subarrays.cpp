class Solution {
public:
    int solve(vector<int>& nums, int k) {
        if (k < 0)
            return 0;
        int left = 0, right = 0, ans = 0;
        int n = nums.size();
        int count = 0;
        while (right < n) {
            if(nums[right] % 2 == 1) count++;
            
            while (count > k) {
                if(nums[left] % 2 == 1) count--;
                left++;
            }
            if (count <= k)
                ans += right - left + 1;
            right++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k - 1);
    }
};