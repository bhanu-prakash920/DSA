class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mp;
        int left = 0, right = 0, len = 0;
        int n = fruits.size();

        while (right < n) {
            mp[fruits[right]]++;

            if (mp.size() > 2) {
                mp[fruits[left]]--;

                if (mp[fruits[left]] == 0) {
                    mp.erase(fruits[left]);
                }

                left++;
            }

            if (mp.size() <= 2) {
                len = max(len, right - left + 1);
                
            }
            right++;
        }

        return len;
    }
};