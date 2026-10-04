class Solution {
public:
    int dijkstra(int n, vector<vector<pair<int, int>>>& adj, int src,
                 int distanceThreshold) {
        // {distance, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        vector<int> dist(n, INT_MAX);

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // Skip outdated entry
            if (d > dist[node])
                continue;

            for (auto it : adj[node]) {
                int nextNode = it.first;
                int weight = it.second;

                if (d + weight < dist[nextNode]) {
                    dist[nextNode] = d + weight;
                    pq.push({dist[nextNode], nextNode});
                }
            }
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (dist[i] <= distanceThreshold)
                count++;
        }
        return count;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        vector<vector<pair<int, int>>> adj(n);
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        int mincount = INT_MAX;
        int res = 0;
        for (int i = 0; i < n; i++) {
            int count = dijkstra(n, adj, i, distanceThreshold);
            if(mincount >= count){
                res = i;
                mincount = count;
            }
            
        }
        return res;
    }
};