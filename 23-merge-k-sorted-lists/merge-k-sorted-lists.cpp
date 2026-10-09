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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head=nullptr;
        for (int i=0;i<lists.size();i++)
        {
        ListNode* temp1=lists[i];
        head=mergesort(head,temp1);
        }
        return head;
    }
};