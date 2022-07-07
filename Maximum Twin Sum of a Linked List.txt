/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> vec;
        ListNode* temp = new ListNode();
        temp = head;
        while (temp != NULL) {
            vec.push_back(temp->val);
            temp = temp->next;
        }
        int sum = 0;
        for (int i = 0, j = vec.size() - 1; i < j; i++, j--) {
            if (sum < vec[i] + vec[j]) sum = vec[i] + vec[j];
        }
        return sum;
    }
};
