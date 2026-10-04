class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        vector<vector<pair<int, int>>> adj(n);
        vector<int> dist(n, INT_MAX);
        int res = INT_MIN;
        for (int i = 0; i < times.size(); i++) {
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];
            adj[u - 1].push_back({v - 1, w});
        }

        pq.push({0, k - 1});
        dist[k - 1] = 0;
        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            int weight = cur.first;
            int node = cur.second;
            if (weight >dist[node])
                continue;
            for (auto it : adj[node]) {
                if (it.second + weight >= dist[it.first])
                    continue;
                dist[it.first] = it.second + weight;
                
                pq.push({dist[it.first], it.first});
            }
        }
        int maxi = *max_element(dist.begin() , dist.end());
        return (maxi == INT_MAX ? -1 : maxi);
    }
};