class Solution {
public:
    int NcR(int n, int r)
    {
        long long p = 1, k = 1;
        if (n - r < r)
            r = n - r;
        if (r != 0) {
            while (r) {
                p *= n;
                k *= r;
                int m = __gcd(p, k);
                p /= m;
                k /= m;
                n--;
                r--;
            }
        }

        else
            p = 1;
        return p;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for (int i = 0; i < numRows; i++) {
            vector<int> vec;
            for (int j = 0; j <= i; j++) vec.push_back(NcR(i, j));
            ans.push_back(vec);
        }
        return ans;
    }
};
