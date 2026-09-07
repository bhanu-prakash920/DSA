class Solution {
public:
    long long calDis(vector<int> point) {
        return point[0] * point[0] + point[1] * point[1];
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<long long, pair<int, int>>,
                       vector<pair<long long, pair<int, int>>>,
                       greater<pair<long long, pair<int, int>>>>
            pq;

        for (auto point : points) {
            long long dis = calDis(point);
            pq.push({dis,{point[0], point[1]}});

        }
        vector<vector<int>> res(k, vector<int>(2));
        for(int i = 0 ; i < k ; i++){
            auto it = pq.top();
            res[i][0] = it.second.first;
            res[i][1] = it.second.second;
            pq.pop();
        }
        return res;
    }
};