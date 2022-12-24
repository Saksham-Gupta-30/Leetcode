class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        unordered_map<string, string> umap;
        for (auto it: positive_feedback) {
            umap[it] = "good";
        }
        for (auto it: negative_feedback) {
            umap[it] = "bad";
        }
        
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < report.size(); i++) {
            int score = 0;
            string word = "";
            for (int j = 0; j < report[i].size(); j++) {
                if (report[i][j] == ' ') {
                    if (umap.find(word) != umap.end()) {
                        if (umap[word] == "good") score += 3;
                        else score -= 1;
                    }
                    word = "";
                    continue;
                }
                else {
                    word += report[i][j];
                }
            }
            if (umap.find(word) != umap.end()) {
                if (umap[word] == "good") score += 3;
                else score -= 1;
            }
            pq.push({score, student_id[i]});
        }
        
        vector<int> ans;
        vector<pair<int, int>> temp;
        while (!pq.empty()) {
            int s = pq.top().first;
            cout << s << " ";
            int id = pq.top().second;
            cout << id << " ";
            pq.pop();
            if (temp.size() != 0) {
                if (temp[0].second == s) temp.push_back({id, s});
                else {
                    sort(temp.begin(), temp.end());
                    for (auto it: temp) {
                        ans.push_back(it.first);
                        k--;
                        if (k == 0) return ans;
                    }
                    temp.clear();
                    temp.push_back({id, s});
                }
            }
            else if (temp.size() == 0) {
                temp.push_back({id, s});
            }
        }
        sort(temp.begin(), temp.end());
        for (auto it: temp) {
            ans.push_back(it.first);
        }
        return ans;
    }
};
