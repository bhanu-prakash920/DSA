class Solution {
public:
    int numberOfSubstrings(string s) {
        int left = 0;
        int right = 0;
        int ans = 0;
        int n = s.length();
        vector<int> mp(3,-1);
        while( right < n){
            mp[s[right] - 'a'] = right;
            if(mp[0] != -1 && mp[1] != -1 && mp[2] != -1 ){
                ans += min(mp[0] , min(mp[1],mp[2])) + 1;
            }
            right++;
        }
        return ans;
    }
};