// this is leetcode daily challenge of 15 Aug 2023
// problem link : https://leetcode.com/problems/partition-list/description/

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* p=head,*q=NULL;
        while(p&&p->val<x)
        {
            q=p;
            p=p->next;
        }

        if(!p)
            return head;
        
        ListNode* p1=p,*p2=p->next;

        while(p2)
        {
            if(p2->val>=x)
            {
                p1=p2;
                p2=p2->next;
            }
            else 
            {
                p1->next=p2->next;
                p2->next=p;
                if(q==NULL)
                {
                    q=p2;
                    head=q;
                }
                else 
                {
                    q->next=p2;
                    q=p2;
                }
                p2=p1->next;
            }
        }

        return head;
    }
};
