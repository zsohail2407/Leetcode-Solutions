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
ListNode* findMiddle(ListNode* head) {
        if (head==nullptr ||head->next==nullptr)
        {
            return nullptr;
        }
        ListNode* s=head;
        ListNode* f=head->next;
        while(f!=nullptr && f->next!=nullptr)
        {
            f=f->next->next;
            s=s->next;
        }
        return s;
    }
    ListNode* mergesort(ListNode* aa, ListNode* aaaa)
    {
        ListNode dummy(0);
        ListNode* temp=&dummy;
        while(aa && aaaa)
        {
        if(aa->val>=aaaa->val)
        {
          temp->next=aaaa;
          aaaa=aaaa->next;
        }
        else
        {
          temp->next=aa;
          aa=aa->next;
        }
        temp=temp->next;
        }
        if(aa)
        {
         temp->next=aa;
        }
        else
        {
         temp->next=aaaa;
        }
        return dummy.next;
    }
class Solution {
public:
    ListNode* sortList(ListNode* head) {
    if(!head || !head->next)
    {
        return head;
    }
    ListNode* middle=findMiddle(head);
    ListNode* temp1= head;
    ListNode* temp2=middle->next;
    middle->next=nullptr;
    temp1=sortList(temp1);
    temp2=sortList(temp2);
    return mergesort(temp1,temp2);
    }
};