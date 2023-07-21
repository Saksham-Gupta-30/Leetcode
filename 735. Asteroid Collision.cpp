class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for (int i = 0; i < asteroids.size(); i++) {
            int it = asteroids[i];
            if (st.empty()) st.push(it);
            else {
                if (it > 0) st.push(it);
                else {
                    if (st.top() > 0) {
                        if (abs(st.top()) == abs(it)) st.pop();
                        else if (abs(st.top()) > abs(it)) continue;
                        else {
                            st.pop();
                            i--;
                        }
                    }
                    else st.push(it);
                }
            }
        }
        vector<int> ans(st.size());
        int i = st.size() - 1;
        while (!st.empty()) {
            ans[i] = st.top();
            i--;
            st.pop();
        }
        return ans;
    }
};
