class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for (auto it: s) mp[it]++;
        priority_queue<pair<int, char>> pq;
        for (auto it: mp) {
            char x = it.first;
            int n = it.second;
            cout << n << " " << x << endl;
            pq.push(make_pair(n, x));
        }
        string ans = "";
        while (!pq.empty()) {
            char x = pq.top().second;
            int n = pq.top().first;
            for (int i = 0; i < n; i++) ans += x;
            pq.pop();
        }
        return ans;
    }
};
