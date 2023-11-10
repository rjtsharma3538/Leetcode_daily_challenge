// this is leetcode daily challenge of 10 Nov 2023
// problem link : https://leetcode.com/problems/restore-the-array-from-adjacent-pairs/description/?envType=daily-question&envId=2023-11-10

class Solution {
public:

    bool help(int node, int n, map<int,vector<int>> &mp, set<int> &visited, set<int> &path_visited, vector<int> &ans)
    {
        if(ans.size()==n)
            return true;
        visited.insert(node);
        for(auto next_node:mp[node])
        {
            if(path_visited.find(next_node)!=path_visited.end())
                return false;
            else if(visited.find(next_node)==visited.end())
            {
                if(!help(next_node,n,mp,visited,path_visited,ans))
                    return false;
            }
        }

        ans.push_back(node);
        return true;
    }

    vector<int> restoreArray(vector<vector<int>>& adj) {
        map<int,vector<int>> mp;
        for(int i=0;i<adj.size();i++)
        {
            mp[adj[i][0]].push_back(adj[i][1]);
            mp[adj[i][1]].push_back(adj[i][0]);
        }

        int ele=-1;
        for(auto it:mp)
        {
            if(it.second.size()==1)
            {
                ele=it.first;
                break;
            }   
        }

        int n=adj.size()+1;
        set<int> visited,path_visited;
        vector<int> ans;
        help(ele,n,mp,visited,path_visited,ans);
        return ans;
    }
};
