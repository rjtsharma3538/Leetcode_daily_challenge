class DisJointSet{

    vector<int> parent,size,rank;
    
public:
    
    DisJointSet(int n)
    {
        parent.resize(n+1);
        size.resize(n+1,1);
        rank.resize(n+1,0);
        
        for(int i=0;i<=n;i++)
            parent[i]=i;
    }
    
    int find_par(int node)
    {
        if(node==parent[node])
            return node;
        return parent[node]=find_par(parent[node]);
    }
    
    void UnionByRank(int u, int v)
    {
        int ult_u=find_par(u);
        int ult_v=find_par(v);
        
        if(ult_u==ult_v)
            return;
        
        if(rank[ult_u]<rank[ult_v])
        {
            parent[ult_u]=ult_v;
        }
        
        else if(rank[ult_v]<rank[ult_u])
        {
            parent[ult_v]=ult_u;
        }
        
        else 
        {
            parent[ult_v]=ult_u;
            rank[ult_u]++;
        }
    }
};

class Solution {
public:

    static bool cmp(vector<int>&a , vector<int>&b) 
    {
        return a[2] < b[2]; 
    }
    
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<int> critical, pscritical ;
        for(int i=0;i<edges.size();i++)
            edges[i].push_back(i); 

        sort(edges.begin(),edges.end(),cmp) ;
        
        int mstwt = findMST(n,edges,-1,-1); 

        for(int i=0;i<edges.size();i++)
        {
            if(mstwt<findMST(n,edges,i,-1))
                critical.push_back(edges[i][3]); 
            else if(mstwt==findMST(n,edges,-1,i)) 
                pscritical.push_back(edges[i][3]);
        }

        return {critical , pscritical};         
    }
    
    int findMST(int &n ,  vector<vector<int>>& edges , int block , int e) {
        DisJointSet uf(n); 
        int weight=0 ;
        if(e!=-1) 
        {
            weight+=edges[e][2]; 
            uf.UnionByRank(edges[e][0],edges[e][1]); 
        }
        
        for(int i=0;i<edges.size();i++)
        {
            if(i==block) 
                continue; 
            if(uf.find_par(edges[i][0])==uf.find_par(edges[i][1]))
                continue; 
            uf.UnionByRank(edges[i][0],edges[i][1]); 
            weight+=edges[i][2]; 
        }
    
        for(int i=0;i<n;i++)
        {
            if(uf.find_par(i)!=uf.find_par(0))
                return INT_MAX;
        }    
        
        return weight; 
    }
};
