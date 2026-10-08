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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp1=head;
        ListNode* temp2=head;
        ListNode* ptr=head;
        for(int i=0;i<n && temp1!=nullptr;i++)
        {
           temp1=temp1->next;
        }
        while(temp1)
        {
            ptr=temp2;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        if(temp2==head)
        {
         head=head->next;
        }
        else
        {
        ptr->next=temp2->next;
        }
        delete temp2;
        return head;
    }
};