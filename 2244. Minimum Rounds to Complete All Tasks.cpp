class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int, int> mp;
        for (auto it: tasks) mp[it]++;

        int round = 0;
        for (auto it: mp) {
            if (it.second == 1) return -1;
            if (it.second == 2) round++;
            else if (it.second == 3) round++;
            else {
                if (it.second % 3 == 0) round += it.second / 3;
                else round = round + (it.second / 3) + 1;
            }
        }
        return round;
    }
};
