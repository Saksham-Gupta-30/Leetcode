 /* Definition for singly-linked list.
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
    ListNode* create(int data)
    {
        ListNode* New = new ListNode();
        New->val = data;
        New->next = NULL;
        return New;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3 = new ListNode();
        l3 = NULL;
        ListNode* temp3 = new ListNode;
        temp3 = l3;
        int carry = 0, data;
        while (l1 != NULL && l2 != NULL)
        {
            data = l1->val + l2->val;
            if (data <= 9)
            {
                if (carry == 1) {
                    data += 1;
                    carry = 0;
                }
                if (data > 9) {
                    carry = 1;
                    data = data % 10;
                }
            }
            else
            {
                if (carry == 0) {
                    carry = 1;
                    data = data % 10;
                }
                else {
                    data += 1;
                    carry = 1;
                    data = data % 10;
                }
            }
            if (l3 == NULL)
            {
                temp3 = create(data);
                l3 = temp3;
            }
            else
            {
                ListNode* New = create(data);
                temp3->next = New;
                temp3 = New;
            }
            l1 = l1->next;
            l2 = l2->next;
            data = 0;
        }
        if (l1 == NULL)
        {
            while (l2 != NULL)
            {
                data = l2->val;
                if (data <= 9)
                {
                    if (carry == 1) {
                        data += 1;
                        carry = 0;
                    }
                    if (data > 9) {
                        carry = 1;
                        data = data % 10;
                    }
                }
                else {
                    data = 0;
                    carry = 1;
                }
                ListNode* New = create(data);
                temp3->next = New;
                temp3 = New;
                l2 = l2->next;
            }
        }
        if (l2 == NULL)
        {
            while (l1 != NULL)
            {
                data = l1->val;
                if (data <= 9)
                {
                    if (carry == 1) {
                        data += 1;
                        carry = 0;
                    }
                    if (data > 9) {
                        carry = 1;
                        data = data % 10;
                    }
                }
                else {
                    data = 0;
                    carry = 1;
                }
                ListNode* New = create(data);
                temp3->next = New;
                temp3 = New;
                l1 = l1->next;
            }
        }
        if (carry != 0) {
            ListNode* New = create(1);
            temp3->next = New;
            temp3 = New;
        }
        return l3;
    }
};
