class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st1, st2;
        for (auto it: s) {
            if (it == '#') {
                if (!st1.empty()) st1.pop();
                else continue;
            }
            else st1.push(it);
        }
        for (auto it: t) {
            if (it == '#') {
                if (!st2.empty()) st2.pop();
                else continue;
            }
            else st2.push(it);
        }
        string x = "";
        while (!st1.empty()) {
            x += st1.top();
            st1.pop();
        }
        string y = "";
        while (!st2.empty()) {
            y += st2.top();
            st2.pop();
        }
        return x == y;
    }
};
