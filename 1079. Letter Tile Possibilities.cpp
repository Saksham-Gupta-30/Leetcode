class Solution {
public:
    void f(string tiles, vector<int>& freq, string ans, set<string>& se) {
        if (ans.size() > 0) {
            if (se.count(ans)) return;
            se.insert(ans);
        }

        for (int i = 0; i < tiles.size(); i++) {
            if (freq[i] == 0) {
                freq[i] = 1;
                f(tiles, freq, ans + tiles[i], se);
                freq[i] = 0;
            }
        }
    }
    int numTilePossibilities(string tiles) {
        vector<int> freq(tiles.size(), 0);
        set<string> se;
        string ans = "";
        f(tiles, freq, ans, se);
        return se.size();
    }
};
