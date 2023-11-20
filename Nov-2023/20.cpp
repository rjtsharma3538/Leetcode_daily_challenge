// this is leetcode daily challenge of 20 Nov 2023
// problem link : https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage/solutions/?envType=daily-question&envId=2023-11-20

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        map<pair<int,char>,int> mp;
        int m=-1,p=-1,g=-1;
        for(int i=garbage.size()-1;i>=0;i--)
        {
            for(auto it:garbage[i])
                mp[{i,it}]++;
            
            if(m==-1&&mp[{i,'M'}]>0)
                m=i;
            if(p==-1&&mp[{i,'P'}]>0)
                p=i;
            if(g==-1&&mp[{i,'G'}]>0)
                g=i;
        }

        int ans=0; 
        for(int i=0;i<m;i++)
        {
            ans+=travel[i];
            ans+=mp[{i,'M'}];
        }

        ans+=mp[{m,'M'}];

        for(int i=0;i<p;i++)
        {
            ans+=travel[i];
            ans+=mp[{i,'P'}];
        }

        ans+=mp[{p,'P'}];

        for(int i=0;i<g;i++)
        {
            ans+=travel[i];
            ans+=mp[{i,'G'}];
        }

        ans+=mp[{g,'G'}];

        return ans;
    }
};
