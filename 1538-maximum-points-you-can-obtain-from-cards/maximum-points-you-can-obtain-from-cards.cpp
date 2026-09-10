class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int leftsum = 0;
        int rightsum = 0;
        int ans = 0;
        int n = cardPoints.size();
        for (int i = 0; i < k; i++) {
            leftsum+=cardPoints[i];

        }
        int right = n-1;
        int left = k-1;
        ans = leftsum;
        
        while(left >= 0){
            leftsum -= cardPoints[left];
            left--;
            rightsum +=cardPoints[right];
            right--;
            ans = max(ans , leftsum + rightsum);
        }
        return ans ;
           
    }
};