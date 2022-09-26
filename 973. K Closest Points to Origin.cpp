class Solution {
public:
    float euclidean(int x, int y) {
        return sqrt((x * x) + (y * y));
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<float, int>, vector<pair<float, int>>, greater<pair<float, int>>> pq;
        for (int i = 0; i < points.size(); i++) {
            float x = euclidean(points[i][0], points[i][1]);
            pq.push(make_pair(x, i));
        }
        
        while (!pq.empty()) {
            if (k == 0) break;
            pair<float, int> p;
            p = pq.top();
            pq.pop();
            ans.emplace_back(points[p.second]);
            k--;
        }
        return ans;
    }
};
