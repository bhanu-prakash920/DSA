class Solution {
public:
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto cmp = [](const vector<int> a, const vector<int> b) {
            long long d1 = 1LL * a[0] * a[0] + 1LL * a[1] * a[1];
            long long d2 = 1LL * b[0] * b[0] + 1LL * b[1] * b[1];
            return d1 < d2;
        };
        priority_queue < vector<int>, vector<vector<int>>, decltype(cmp)>  pq;

        for (auto point : points) {
            
            pq.push(point);
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<vector<int>> res;
        while (!pq.empty()) {
            res.push_back(pq.top());
            pq.pop();
        }
        return res;
    }
};