class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        int fresh = 0,rotten = 0;
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i,j},0});
                }
                if(grid[i][j] == 1) fresh++;
                
            }
        }
        int maxtime = 0;
        while(!q.empty()){
            auto pos = q.front();
            int r = pos.first.first;
            int c = pos.first.second;
            int time = pos.second;
            q.pop();
            maxtime = max(maxtime, time);
            for(int i = 0 ; i < 4 ; i++){
                int nr = dr[i] + r;
                int nc = dc[i] + c;
                if(nr >=0 && nc >=0  &&nr < m && nc < n && grid[nr][nc]==1 ){
                    
                    grid[nr][nc] = 2;
                    rotten++;
                    q.push({{nr,nc},time+1});
                }
            }
        }
        if(rotten == fresh) return maxtime;
        return  -1;
    }
};