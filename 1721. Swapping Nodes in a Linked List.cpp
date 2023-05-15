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
    ListNode* swapNodes(ListNode* head, int k) {
        if (head->next == NULL) return head;
        ListNode* first = nullptr;
        ListNode* temp = head;
        int count = 0;
        while (temp != NULL) {
            if (count == k - 1) first = temp;
            temp = temp->next;
            count++;
        }
        temp = head;
        count = count - k;
        while (count--) {
            temp = temp->next;
        }
        swap(temp->val, first->val);
        return head;
    }
};
