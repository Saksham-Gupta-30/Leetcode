class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 == 1) return false;
        stack<char> st;
        for (auto it: s) {
            if (it == '(' || it == '[' || it == '{') st.push(it);
            else if (it == ')') {
                if (st.empty() || st.top() != '(') return false;
                else st.pop();
            }
            else if (it == ']') {
                if (st.empty() || st.top() != '[') return false;
                else st.pop();
            }
            else if (it == '}') {
                if (st.empty() || st.top() != '{') return false;
                else st.pop();
            }
        }
        if (!st.empty()) return false;
        return true;
    }
};
