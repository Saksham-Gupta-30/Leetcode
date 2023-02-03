class Solution {
public:
    int Max(int a, int b) {
        return a >= b ? a : b;
    }
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        unordered_map<char, bool> umap;
        for (char i = 'a'; i <= 'z'; i++) umap[i] = 0;
        queue<char> q;
        for (auto it: s) {
            if (umap[it] == 0) {
                umap[it] = 1;
                q.push(it);
            }
            else {
                while (!q.empty()) {
                    if (q.front() == it) {
                        umap[it] = 0;
                        q.pop();
                        break;
                    }
                    else {
                        umap[q.front()] = 0;
                        q.pop();
                    }
                }
                q.push(it);
                umap[it] = 1;
            }
            cout << ans << " " << q.size() << endl;
            ans = Max(ans, q.size());
        }
        return ans;
    }
};
