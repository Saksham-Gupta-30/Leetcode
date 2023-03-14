class Solution {
public:
    int myAtoi(string s) {
        bool isPos = true, isNum = false, sign = false;
        long neg = -2147483648;
        long pos = 2147483648;
        long num = 0;
        for (auto &it: s) {
            if (it == ' ') {
                if (sign || isNum) break;
            }
            else if (it == '-' || it == '+') {
                if (isNum) break;
                if (sign) return 0;
                sign = true;
                if (it == '-') isPos = false;
            }
            else if (it >= 48 && it <= 57) {
                isNum = true;
                num = num * 10 + (it - '0');
                if (num > pos) num = pos;
            }
            else if (isNum == true) break;
            else if (isNum == false && it != ' ') break;
        }
        if (isPos) return num == pos ? pos - 1 : num;
        return -num;
    }
};
