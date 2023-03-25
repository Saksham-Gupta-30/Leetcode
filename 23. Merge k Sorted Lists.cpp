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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;

        ListNode* head;
        ListNode* tail;
        ListNode* p1 = list1;
        ListNode* p2 = list2;
        if (p1->val <= p2->val) {
            head = p1;
            tail = p1;
            p1 = p1->next;
        }
        else {
            head = p2;
            tail = p2;
            p2 = p2->next;
        }
        while (p1 && p2) {
            if (p1->val <= p2->val) {
                tail->next = p1;
                p1 = p1->next;
            }
            else {
                tail->next = p2;
                p2 = p2->next;
            }
            tail = tail->next;
        }
        if (p1) tail->next = p1;
        if (p2) tail->next = p2;
        return head;
    }
    ListNode* mergeK(vector<ListNode*>& lists, int i, int j) {
        if (i == j) return lists[i];
        int m = i + (j - i) / 2;
        ListNode* h1 = mergeK(lists, i, m);
        ListNode* h2 = mergeK(lists, m + 1, j);
        return mergeTwoLists(h1, h2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return NULL;
        return mergeK(lists, 0, lists.size() - 1);
    }
};
