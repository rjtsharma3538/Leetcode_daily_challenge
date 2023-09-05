// this is leetcode daily challenge of 5 Sept 2023
// problem link : https://leetcode.com/problems/copy-list-with-random-pointer/description/?envType=daily-question&envId=2023-09-05

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* first=NULL,*last=NULL;
        Node* p=head;
        map<Node*,vector<pair<Node*,Node*>>> mp;
        while(head)
        {
            Node* t=new Node(head->val);
            if(first==NULL)
            {
                first=t;
                last=t;
            }
            else 
            {
                last->next=t;
                last=t;
            }
            mp[head->random].push_back({head,last});
            head=head->next;
        }

        Node* q=first;
        while(p&&q)
        {
            for(auto it:mp[p])
            {
                it.second->random=q;
            }
            p=p->next;
            q=q->next;
        }

        return first;
    }
};
