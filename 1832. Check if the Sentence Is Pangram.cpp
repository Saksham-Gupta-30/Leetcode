class Solution {
public:
    bool checkIfPangram(string sentence) {
        int check[27] = {0};
        for (int i = 0; i < sentence.size(); i++) {
            check[sentence[i] - 'a' + 1] = 1;
        }
        for (int i = 1; i < 27; i++) if (check[i] != 1) return false;
        return true;
    }
};
