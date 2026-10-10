class Solution {
public:
    int minInsertions(string s) {
        string s1 = s;
        reverse(s.begin(), s.end());
        string s2 = s;
        int n = s.size();
        vector<int> dp(n + 1, 0);
        vector<int> curr(n + 1, 0);
        int prev = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    curr[j] = 1+  dp[j - 1];
                } else {
                    curr[j] = max(dp[j], prev);
                }
                prev = curr[j];
            }
            dp = curr;
            prev = 0;
        }
        return n - dp[n];
    }
};