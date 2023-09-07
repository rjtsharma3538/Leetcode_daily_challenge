// this is leetcode daily challenge of 7 Sept 2023
// problem link : https://leetcode.com/problems/split-linked-list-in-parts/description/?envType=daily-question&envId=2023-09-06

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

    int count(ListNode* last)
    {
        int cnt=0;
        while(last)
        {
            cnt++;
            last=last->next;
        }
        return cnt;
    }

    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int length=count(head);
        cout<<length<<endl;
        int x=length/k;
        int rem=length%k;

        vector<ListNode*> v;
        while(v.size()<k)
        {
            if(head)
            {
                ListNode* p=head,*q=NULL;
                if(rem)
                {
                    for(int i=0;i<=x;i++)
                    {
                        q=p;
                        p=p->next;
                    }

                    q->next=NULL;
                    v.push_back(head);
                    head=p;
                    rem--;
                }
                else 
                {
                    for(int i=0;i<x;i++)
                    {
                        q=p;
                        p=p->next;
                    }

                    q->next=NULL;
                    v.push_back(head);
                    head=p;
                }
            }
            else 
                v.push_back(NULL);
        }

        return v;
    }
};
