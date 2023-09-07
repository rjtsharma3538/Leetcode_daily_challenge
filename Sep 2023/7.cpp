// this is leetcode daily challenge of 7 Sept 2023
// problem link : https://leetcode.com/problems/reverse-linked-list-ii/description/?envType=daily-question&envId=2023-09-07

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

    pair<ListNode*,ListNode*> rev(ListNode* left, ListNode* right)
    {
        ListNode* p=left,*q=NULL,*r=NULL,*last=left;
        while(p)
        {
            r=q;
            q=p;
            cout<<p->val<<endl;
            p=p->next;
            q->next=r;

            if(q==right)
                break;
        }
        return {q,last};
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* l=NULL,*r=NULL,*p=head,*prev=NULL;
        for(int i=1;i<=right;i++)
        {
            if(i<=left)
            {
                prev=l;
                l=p;
            }
            r=p;
            p=p->next;
        }

        cout<<l->val<<" "<<r->val<<endl;
        ListNode*  start,*end;
        start=rev(l,r).first;
        end=rev(l,r).second;

        end->next=p;
        if(left==1)
            return start;
        prev->next=start;
        return head;
    }
};
