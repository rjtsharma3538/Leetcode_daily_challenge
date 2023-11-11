// this is leetcode daily challenge of 11 Nov 2023
// problem link : https://leetcode.com/problems/design-graph-with-shortest-path-calculator/solutions/?envType=daily-question&envId=2023-11-11

class Graph {
public:

    vector<pair<int,int>> adj[101];
    Graph(int n, vector<vector<int>>& edges) {
        for(int i=0;i<edges.size();i++)
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1],edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,node1});
        vector<int> distance(101,1e9);
        distance[node1]=0;

        while(!pq.empty())
        {
            int node=pq.top().second;
            int dist=pq.top().first;
            pq.pop();

            for(auto it:adj[node])
            {
                int next_node=it.first;
                int d=it.second;

                if(d+dist<distance[next_node])
                {
                    distance[next_node]=d+dist;
                    pq.push({d+dist,next_node});
                }
            }
        }

        if(distance[node2]==1e9)
            return -1;
        return distance[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
