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
    ListNode* oddEvenList(ListNode* head) {
        vector<int> vec;
        ListNode* temp = head;
        while (temp != NULL) {
            vec.push_back(temp->val);
            temp = temp->next;
        }
        temp = head;
        int i = 0;
        while (temp != NULL) {
            temp->val = vec[i];
            i = i + 2;
            if (i > vec.size() - 1) i = 1;
            temp = temp->next;
        }
        return head;
    }
};
