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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int cnt = 0;
        ListNode* curr = head;
        while (curr && cnt != k) {
            cnt++;
            curr = curr->next;
        }
        if (cnt < k) return head;
        cnt = 0;
        curr = head;
        ListNode* prev = NULL;
        ListNode* tmp;
        while (cnt != k) {
            tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
            cnt++;
        }
        
        head->next = reverseKGroup(curr, k);
        return prev;
    }
};
