class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int n = nums.size();
        int right = n - 1;
        if( n == 0 || n == 1) return n-1;
         if(nums[left] > nums[left+1]) return left;
        if(nums[right] > nums[right-1]) return right;
        while(left <= right){
            int mid = left + (right - left) / 2;

            if(mid+1 <n && mid -1 >=0 && nums[mid] > nums[mid - 1] && nums[mid] > nums[mid+1] ){
                return mid;
            }
            else if( mid -1 >=0 && nums[mid] <= nums[mid - 1]){
                right = mid-1;

            }
            else if( mid+1 <n ){
                left = mid+1;
            }

        }
        return -1;
    }
};