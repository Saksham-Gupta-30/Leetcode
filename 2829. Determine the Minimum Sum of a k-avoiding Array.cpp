class Solution {
public:
    int minimumSum(int n, int k) {
        unordered_set<int> st;
        int i = 1, sum = 0;
        while (st.size() != n) {
            if (st.find(k - i) == st.end()) {
                st.insert(i);
                sum += i;
            }
            i++;
        }
        return sum;
    }
};
