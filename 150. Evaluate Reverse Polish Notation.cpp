class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if (tokens.size() == 1) return stol(tokens[0]);
        stack<string> st;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "/" || tokens[i] == "*") {
                string x = st.top();
                st.pop();
                string y = st.top();
                st.pop();
                if (tokens[i] == "+") st.push(to_string(stol(y) + stol(x)));
                else if (tokens[i] == "-") st.push(to_string(stol(y) - stol(x)));
                else if (tokens[i] == "/") st.push(to_string(stol(y) / stol(x)));
                else st.push(to_string(stol(y) * stol(x)));
            }
            else st.push(tokens[i]);
        }
        return stol(st.top());
    }
};
