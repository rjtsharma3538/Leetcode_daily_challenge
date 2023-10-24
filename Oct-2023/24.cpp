// this is leetcode daily challenge of 24 Oct 2023
// problem link : https://leetcode.com/problems/find-largest-value-in-each-tree-row/?envType=daily-question&envId=2023-10-24

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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> q;
        if(!root)
            return {};
        q.push(root);
        vector<int> v;

        while(!q.empty())
        {
            int sz=q.size(),maxi=INT_MIN;
            for(int i=0;i<sz;i++)
            {
                root=q.front();
                q.pop();

                maxi=max(maxi,root->val);

                if(root->left)
                    q.push(root->left);
                if(root->right)
                    q.push(root->right);
            }
            v.push_back(maxi);
        }

        return v;
    }
};
