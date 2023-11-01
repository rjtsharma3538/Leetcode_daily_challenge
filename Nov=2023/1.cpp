// this is leetcode daily challenge of 1 nov 2023
// problem link : https://leetcode.com/problems/find-mode-in-binary-search-tree/description/?envType=daily-question&envId=2023-11-01

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

    void inorder(TreeNode* root, vector<int> &v, int &cnt, int &maxi, int &prev)
    {
        if(!root)
            return;
        inorder(root->left,v,cnt,maxi,prev);
        if(root->val==prev)
            cnt++;
        else 
        {
            if(cnt==maxi)
                v.push_back(prev);
            else if(cnt>maxi)
            {
                v={prev};
                maxi=cnt;
            }
            cnt=1;
            prev=root->val;
        }
        inorder(root->right,v,cnt,maxi,prev);
    }

    vector<int> findMode(TreeNode* root) {
        int cnt=0,maxi=0,prev=-1;
        vector<int> v;
        inorder(root,v,cnt,maxi,prev);
        if(cnt==maxi)
            v.push_back(prev);
        else if(cnt>maxi)
            v={prev};
        cout<<cnt<<endl;
        return v;    
    }
};
