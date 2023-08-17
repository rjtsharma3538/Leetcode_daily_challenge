// this is leetcode daily challenge of 17 Aug 2023
// problem link : https://leetcode.com/problems/01-matrix/description/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> distance(m,vector<int> (n,-1));
        queue<pair<int,int>> q;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==0)
                {
                    distance[i][j]=0;
                    q.push({i,j});
                }
            }
        }

        int dist=1;
        int dr[]={1,0,-1,0};
        int dc[]={0,1,0,-1};

        while(!q.empty())
        {
            int sz=q.size();
            for(int i=0;i<sz;i++)
            {
                int row=q.front().first;
                int col=q.front().second;
                q.pop();
                
                for(int j=0;j<4;j++)
                {
                    int next_row=row+dr[j];
                    int next_col=col+dc[j];

                    if(next_row>=0&&next_row<m&&next_col>=0&&next_col<n&&mat[next_row][next_col]==1&&distance[next_row][next_col]==-1)
                    {
                        distance[next_row][next_col]=dist;
                        q.push({next_row,next_col});
                    }
                }
            }
            dist++;
        }
        return distance;
    }
};
