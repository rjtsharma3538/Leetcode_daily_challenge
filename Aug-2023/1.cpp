// this is leetcode daily challenge of 1 Aug 2023
// problem link : https://leetcode.com/problems/combinations/

class Solution {
public:

    void help(int n, int num, int k, vector<int> &v, vector<vector<int>> &ans)
    {
        if(num>n)
        {
            if(v.size()==k)
                ans.push_back(v);
            return;
        }

        v.push_back(num);
        help(n,num+1,k,v,ans);
        v.pop_back();
        help(n,num+1,k,v,ans);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> v;

        help(n,1,k,v,ans);

        return ans;    
    }
};
