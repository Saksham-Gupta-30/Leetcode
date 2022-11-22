class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<vector<int>> q;
        q.push(rooms[0]);
        vector<int> vis(rooms.size(), 0);
        vis[0] = 1;
        while (!q.empty()) {
            vector<int> temp = q.front();
            q.pop();
            for (auto it: temp) {
                if (!vis[it]) {
                    q.push(rooms[it]);
                    vis[it] = 1;
                }
            }
        }
        for (auto it: vis) if (it == 0) return false;
        return true;
    }
};
