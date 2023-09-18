// this is leetcode daily challenge of 18 Sept 2023
// problem link : https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/description/?envType=daily-question&envId=2023-09-18

class Solution {
public:

    int help(vector<int> &v)
    {
        int s=0,e=v.size()-1,mid;
        if(v[s]==0)
            return 0;
        if(v[e]==1)
            return v.size();
        int ans=-1;
        while(s<=e)
        {
            mid=s+(e-s)/2;
            if(v[mid]==1)
            {
                ans=mid+1;
                s=mid+1;
            }
            else 
                e=mid-1;
        }
        return ans;
    }

    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n,m;
        n=mat.size();
        m=mat[0].size();
        priority_queue<pair<int,int>> pq;

        for(int i=0;i<n;i++)
        {
            int x=help(mat[i]);
            cout<<x<<endl;
            pq.push({x,i});

            if(pq.size()>k)
                pq.pop();
        }

        vector<int> ans;
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};
