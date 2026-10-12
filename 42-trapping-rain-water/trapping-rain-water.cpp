
class Solution {
public:
    int trap(vector<int>& height) {
        int lmax = 0, rmax = 0;
        int left = 0;
        int right = height.size() - 1;
        int res = 0;

        while (left < right) {
            if (height[left] <= height[right]) {
                lmax = max(lmax, height[left]);
                res += lmax - height[left];
                left++;
            } else {
                rmax = max(rmax, height[right]);
                res += rmax - height[right];
                right--;
            }
        }

        return res;
    }
};
