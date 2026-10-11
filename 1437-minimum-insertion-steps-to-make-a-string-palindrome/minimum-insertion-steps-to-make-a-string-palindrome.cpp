class Solution {
public:
    int minInsertions(string s) {
        string s1 = s;
        reverse(s.begin(), s.end());
        string s2 = s;
        int n = s.size();
        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            int diagonal = 0;
            for (int j = 1; j <= n; j++) {

                int old = dp[j];
                if (s1[i - 1] == s2[j - 1]) {
                    dp[j] = 1 + diagonal;
                } else {
                    dp[j] = max(dp[j], dp[j - 1]);
                }
                diagonal = old;
            }
        }
        return n - dp[n];
    }
};