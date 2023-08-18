// this is leetcode daily challenge of 18 Aug 2023
// problem link : https://leetcode.com/problems/maximal-network-rank/

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        map<int,int> mp;
        set<pair<int,int>> st;
        
        for(int i=0;i<roads.size();i++)
        {
            mp[roads[i][0]]++;
            mp[roads[i][1]]++;
            st.insert({roads[i][0],roads[i][1]});
        }

        int maxi=0;

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int ans;
                ans=mp[i]+mp[j];
                if(st.find({i,j})!=st.end()||st.find({j,i})!=st.end())
                    ans--;
                maxi=max(maxi,ans);
            }
        }

        return maxi;
    }
};
