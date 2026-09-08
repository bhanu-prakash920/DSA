class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        vector<int> mp(2, 0);

        int l = 0, r = 0, res = 0;
        int n = nums.size();

        while (r < n) {
            mp[nums[r]]++;

             if(mp[0] > k) {
                mp[nums[l]]--;
                l++;
            }

            if(mp[0] <= k)res = max(res, r - l + 1);

            r++;
        }

        return res;
    }
};