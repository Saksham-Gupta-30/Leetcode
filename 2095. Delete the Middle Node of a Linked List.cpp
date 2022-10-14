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
    ListNode* deleteMiddle(ListNode* head) {
        if (head->next == NULL) return NULL;
        ListNode* temp = head;
        ListNode* temp2 = head;
        ListNode* del = temp2;
        while (temp != NULL && temp->next != NULL) {
            temp = temp->next->next;
            del = temp2;
            temp2 = temp2->next;
        }
        del->next = temp2->next;
        temp2->next = NULL;
        return head;
    }
};
