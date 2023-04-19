class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') st.push(i);
            if (s[i] == ')') {
                if (!st.empty()) st.pop();
                else s[i] = '0';
            }
        }
        string ans = "";
        while (!st.empty()) {
            s[st.top()] = '0';
            st.pop();
        }
        for (auto &it: s) if (it != '0') ans += it;
        return ans;
    }
};
