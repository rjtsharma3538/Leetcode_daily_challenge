// this is leetcode daily challenge of 5 Aug 2023
// problem link : https://leetcode.com/problems/unique-binary-search-trees-ii/

class Solution {
public:

    vector<TreeNode*> help(int start, int end)
    {
        vector<TreeNode*> ans;
        if(start>end)
        {
            ans.push_back(NULL);
            return ans;
        }

        for(int i=start;i<=end;i++)
        {
            vector<TreeNode*> left=help(start,i-1);
            vector<TreeNode*> right=help(i+1,end);

            for(int j=0;j<left.size();j++)
            {
                for(int k=0;k<right.size();k++)
                {
                    TreeNode* root=new TreeNode(i);
                    root->left=left[j];
                    root->right=right[k];

                    ans.push_back(root);
                }
            }
        }

        return ans;
    }

    vector<TreeNode*> generateTrees(int n) {
        return help(1,n);
    }
};
