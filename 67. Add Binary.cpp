class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        int x = a.size() - 1;
        int y = b.size() - 1;
        vector<char> ans;
        while (x >= 0 && y >= 0) {
            if (a[x] == '1' && b[y] == '1') {
                if (carry == 1) {
                    ans.push_back('1');
                }
                else {
                    ans.push_back('0');
                    carry = 1;
                }
            }
            else if ((a[x] == '1' && b[y] == '0')||(a[x] == '0' && b[y] == '1')) {
                if (carry == 1) {
                    ans.push_back('0');
                }
                else {
                    ans.push_back('1');
                }
            }
            else if (a[x] == '0' && b[y] == '0') {
                if (carry == 1) {
                    ans.push_back('1');
                    carry = 0;
                }
                else {
                    ans.push_back('0');
                }
            }
            x--;
            y--;
        }
        while (x >= 0) {
            if (carry == 1) {
                if (a[x] == '1') {
                    ans.push_back('0');
                }
                else {
                    ans.push_back('1');
                    carry = 0;
                }
            }
            else {
                ans.push_back(a[x]);
            }
            x--;
        }
        while (y >= 0) {
            if (carry == 1) {
                if (b[y] == '1') {
                    ans.push_back('0');
                }
                else {
                    ans.push_back('1');
                    carry = 0;
                }
            }
            else {
                ans.push_back(b[y]);
            }
            y--;
        }
        if (carry == 1) ans.push_back('1');
        string z = "";
        for (int i = ans.size() - 1; i >= 0; i--) {
            z += ans[i];
        }
        return z;
    }
};
