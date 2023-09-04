// this is leetcode daily challenge of 4 Sept 2023
// problem link : https://leetcode.com/problems/linked-list-cycle/description/?envType=daily-question&envId=2023-09-04

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
    bool hasCycle(ListNode *head) {
        ListNode* fast=head,*slow=head;
        while(fast)
        {
            fast=fast->next;
            if(fast)
            {
                slow=slow->next;
                fast=fast->next;
            }

            if(fast==slow)
                return true;
        }
        return false;
    }
};
