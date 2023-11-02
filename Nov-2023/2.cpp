// this is leetcode daily challenge of 2 Nov 2023
// problem link : https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/?envType=daily-question&envId=2023-11-02

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    pair<int,int> help(TreeNode* root, int &cnt)
    {
        if(!root)
            return {0,0};
        pair<int,int> l,r;
        l=help(root->left,cnt);
        r=help(root->right,cnt);

        int count,sum;
        count=l.second+r.second+1;
        sum=l.first+r.first+root->val;

        if(root->val==sum/count)
            cnt++;
        return {sum,count};
    }

    int averageOfSubtree(TreeNode* root) {
        int cnt=0;
        help(root,cnt);
        return cnt;
    }
};
