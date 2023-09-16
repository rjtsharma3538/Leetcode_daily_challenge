// this is leetcode daily challenge of 16 Sept 2023
// problem link : https://leetcode.com/problems/path-with-minimum-effort/description/?envType=daily-question&envId=2023-09-16

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size(),m=heights[0].size();
        vector<vector<int>> difference(n,vector<int> (m,1e7));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        difference[0][0]=0;

        int dr[]={1,-1,0,0};
        int dc[]={0,0,1,-1};

        while(!pq.empty())
        {
            int diff=pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            pq.pop();

            if(x==n-1&&y==m-1)
                return diff;

            for(int i=0;i<4;i++)
            {
                int next_row=x+dr[i];
                int next_col=y+dc[i];

                if(next_row<0||next_row>=n||next_col<0||next_col>=m)
                    continue;

                int new_diff=max(diff,abs(heights[next_row][next_col]-heights[x][y]));
                if(difference[next_row][next_col]>new_diff)
                {
                    difference[next_row][next_col]=new_diff;
                    pq.push({new_diff,{next_row,next_col}});
                }
            }
        }
        return -1;
    }
};
