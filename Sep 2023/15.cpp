// this is leetcode daily challenge of 15 Sept 2023
// problem link : https://leetcode.com/problems/min-cost-to-connect-all-points/?envType=daily-question&envId=2023-09-15

class DisJointSet
{
    vector<int> parent,size;
    
public:
    
    DisJointSet(int n)
    {
        parent.resize(n+1);
        size.resize(n+1,1);
        
        for(int i=0;i<=n;i++)
            parent[i]=i;
    }
    
    int find_par(int node)
    {
        if(node==parent[node])
            return node;
        return parent[node]=find_par(parent[node]);
    }
    
    void UnionBySize(int u, int v)
    {
        int ult_u=find_par(u);    
        int ult_v=find_par(v);  
        
        
        if(ult_u==ult_v)       
            return;
        
        if(size[ult_u]<size[ult_v])
        {
            parent[ult_u]=ult_v;
            size[ult_v]+=size[ult_u];
        }
        
        else
        {
            parent[ult_v]=ult_u;
            size[ult_u]+=size[ult_v];
        }
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<pair<int,pair<int,int>>> v;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int dist=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                v.push_back({dist,{i,j}});
            }
        }

        DisJointSet ds(n);
        sort(v.begin(),v.end());
        int cost=0;

        for(int i=0;i<v.size();i++)
        {
            int dist=v[i].first;
            int x=v[i].second.first;
            int y=v[i].second.second;

            if(ds.find_par(x)!=ds.find_par(y))
            {
                ds.UnionBySize(x,y);
                cost+=dist;
            }
        }

        return cost;
    }
};
