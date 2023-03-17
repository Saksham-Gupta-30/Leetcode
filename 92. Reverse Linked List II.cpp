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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        while (left > 1) {
            prev = curr;
            curr = curr->next;
            left--, right--;
        }

        ListNode* prevHead = prev;
        ListNode* tail = curr;
        while (right > 0) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
            right--;
        }

        if (prevHead == NULL) head = prev;
        else prevHead->next = prev;
        tail->next = curr;
        return head;
    }
};
