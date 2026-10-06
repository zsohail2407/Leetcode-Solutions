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
        if (head==nullptr ||head->next==nullptr)
        {
            return nullptr;
        }
        ListNode* s=head;
        ListNode* f=head;
        ListNode* temp=nullptr;
        while(f!=nullptr && f->next!=nullptr)
        {
            temp=s;
            f=f->next->next;
            s=s->next;
        }
        temp->next=s->next;
        return head;
    }
};