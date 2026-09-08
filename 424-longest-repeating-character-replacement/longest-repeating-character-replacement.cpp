class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> mp(256, 0);
        int left = 0, right = 0, len = 0;
        int maxfreq = 0;
        int n = s.size();
        while (right < n) {
            mp[s[right]]++;
            maxfreq = max(maxfreq, mp[s[right]]);
            if(right - left + 1 - maxfreq > k){
                mp[s[left]]--;
                left++;
            }
            if (right - left + 1 - maxfreq <= k)
                len = max(len, right - left + 1);
            right++;
        }
        return len;
    }
};