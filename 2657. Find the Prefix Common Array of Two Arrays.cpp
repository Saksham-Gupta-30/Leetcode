class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> ans;
        int cnt = 0;
        unordered_set<int> st;
        for (int i = 0; i < A.size(); i++) {
            if (st.count(A[i])) cnt++;
            else st.insert(A[i]);
            
            if (st.count(B[i])) cnt++;
            else st.insert(B[i]);
            
            ans.push_back(cnt);
        }
        return ans;
    }
};
