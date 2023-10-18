// this is leetcode daily challenge of 18 Oct 2023
// problem link : https://leetcode.com/problems/parallel-courses-iii/editorial/?envType=daily-question&envId=2023-10-18

class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> indegree(n+1,0);
        vector<int> adj[n+1];

        for(int i=0;i<relations.size();i++)
        {
            adj[relations[i][0]].push_back(relations[i][1]);
            indegree[relations[i][1]]++;
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        for(int i=1;i<=n;i++)
        {
            if(indegree[i]==0)
                q.push({time[i-1],i});
        }

        int ans=0;
        
        while(!q.empty())
        {
            int course=q.top().second;
            int t=q.top().first;
            q.pop();

            ans=max(ans,t);

            for(auto it:adj[course])
            {
                indegree[it]--;
                if(indegree[it]==0)
                {
                    q.push({t+time[it-1],it});
                }
            }
        }

        return ans;
    }
};
