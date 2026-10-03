class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int dr[4] = {0, -1, 0, 1};
        int dc[4] = {-1, 0, 1, 0};
        int m = isWater.size();
        int n = isWater[0].size();
        queue<pair<int, int>> q;
        vector < vector<int> >res(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isWater[i][j]) {
                    q.push({i, j});

                } else {
                    res[i][j] = INT_MAX;
                }
            }
        }
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int  nr = dr[i] + r;
                 int nc = dc[i] + c;
                if (nr < m && nr >= 0 && nc < n && nc >= 0 &&
                    !isWater[nr][nc]) {
                    res[nr][nc] = res[r][c] + 1;
                    q.push({nr, nc});
                    isWater[nr][nc] = 1;
                }
            }
        }
        return res;
    }
};