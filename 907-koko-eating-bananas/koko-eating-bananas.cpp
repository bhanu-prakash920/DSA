class Solution {
public:
    bool eat(vector<int>& piles, int h, int k) {
        long long  TimeTaken = 0;

        for (auto& it : piles) {
            TimeTaken += ceil((it + k - 1) / k);
        }
        if (TimeTaken <= h)
            return true;
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int left = 1;
        int right = *max_element(piles.begin(),piles.end() );
        int res = INT_MAX;
        while(left <=right){
            int mid = left + (right - left )/2;
            if(eat(piles,h,mid)){
                res = mid;
                right = mid - 1;
            }
            else left = mid + 1;
        }
        return res;
    }
};