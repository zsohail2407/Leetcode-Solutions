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
    ListNode* reverseKGroup(ListNode* head, int k) {
      ListNode* n = new ListNode;
      n->val=0;
      n->next=head;
      ListNode* aaaa=n;
      while(true)
      {
      ListNode* kthNode=aaaa;
      for(int i=0;i<k;i++)
      {
        if (kthNode!=nullptr)
        {
            kthNode=kthNode->next;
        }
      }
        if(kthNode==nullptr)
        {
            break;
        }
        ListNode* n1=kthNode->next;
        ListNode* temp1=n1;
        ListNode* temp2=aaaa->next;
        while(temp2!=n1)
        {
            ListNode* t=temp2->next;
            temp2->next=temp1;
            temp1=temp2;
            temp2=t;
        }
        ListNode* old=aaaa->next;
        aaaa->next=kthNode;
        aaaa=old;
      }
      return n->next;
    }
};