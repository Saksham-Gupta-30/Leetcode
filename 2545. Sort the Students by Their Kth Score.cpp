int y;
bool comp(vector<int>& a, vector<int>& b) {
    return a[y] > b[y];
}
class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        y = k;
        sort(score.begin(), score.end(), comp);
        return score;
    }
};
