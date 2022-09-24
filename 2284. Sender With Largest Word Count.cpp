class Solution {
public:
    int wordCount(string s) {
        int count = 1;
        for (auto it: s) {
            if (it == ' ') count++;
        }
        return count;
    }
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        map<string, int> mp;
        for (int i = 0; i < messages.size(); i++) {
            int x = wordCount(messages[i]);
            mp[senders[i]] += x;
        }
        string ans = "";
        int MAX = 0;
        for (auto it: mp) {
            if (it.second >= MAX) {
                MAX = it.second;
                ans = it.first;
            }
        }
        return ans;
    }
}; 
