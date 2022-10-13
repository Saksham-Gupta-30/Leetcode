/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *temp = new ListNode;
        temp = node;
        while(node->next != NULL)
        {
            node->val = node->next->val;
            temp = node;
            node = node->next;
        }
        //node->val = node->next->val;
        temp->next = NULL;
    }
};
