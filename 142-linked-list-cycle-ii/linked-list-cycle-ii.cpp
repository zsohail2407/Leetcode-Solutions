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
    ListNode *detectCycle(ListNode *head) {
        bool check=false;
        ListNode* temp1=head;
        ListNode* temp2=head;
        while(temp2 && temp2->next)
        {
            temp2=temp2->next->next;
            temp1=temp1->next;
            if (temp1==temp2)
            {
                check=true;
                break;
            }
        }
        if(!check)
        {
        return nullptr;
        }
        temp2=head;
        while(temp2!=temp1)
        {
            temp2=temp2->next;
            temp1=temp1->next;
        }
        return temp1;
    }
};