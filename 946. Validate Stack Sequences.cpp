class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i = 0;
        int n = pushed.size();
        stack<int> st;
        for (auto &it: pushed) {
            if (it == popped[i]) {
                i++;
                if (!st.empty()) {
                    while (!st.empty() && st.top() == popped[i]) {
                        st.pop();
                        i++;
                    }    
                }
            }
            else st.push(it);
        }
        if (i == n) return true;
        return false;
    }
};
