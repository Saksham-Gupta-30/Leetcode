class Solution {
public:
    bool isValid(string a, string b) {
        int cnt = 0;
        for (int i = 0; i < 8; i++) {
            if (a[i] != b[i]) cnt++;
        }
        return cnt == 1;
    }
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_map<string, bool> mp;
        for (auto& s: bank) mp[s] = true;
        if (mp.find(endGene) == mp.end()) return -1;
        queue<pair<string, int>> q;
        q.push({startGene, 0});
        while (!q.empty()) {
            string s = q.front().first;
            int mutation = q.front().second;
            q.pop();

            for (auto& it: bank) {
                if (mp[it] == true && isValid(s, it)) {
                    if (it == endGene) return mutation + 1;
                    q.push({it, mutation + 1});
                    mp[it] = false;
                }
            }
        }
        return -1;
    }
};
