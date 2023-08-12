// this is leetcode daily challenge of 12 Aug 2023
// problem link : https://leetcode.com/problems/unique-paths-ii/

class Solution {
public:

    int help(int i, int j, vector<vector<int>> &v, vector<vector<int>> &dp)
    {
        if(i==0&&j==0)
        {
            if(v[i][j]==0)
                return dp[i][j]=1;
            return dp[i][j]=0;
        }

        if(i==0)
        {
            if(v[i][j]==0)
                return dp[i][j]=dp[i][j-1];
            return dp[i]
        }
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
    }
};
