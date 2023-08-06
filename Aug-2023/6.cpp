// this is leetcode daily challenge of 7 Aug 2023
// problem link : https://leetcode.com/problems/number-of-music-playlists/description/

class Solution {
public:

    const int mod=1e9+7;

    long long int help(int count_song, int count_unique, int goal, int n, int k, vector<vector<long long int>> &dp)
    {
        if(count_song==goal)
        {
            if(count_unique==n)
                return dp[count_song][count_unique]=1;
            return dp[count_song][count_unique]=0;
        }

        if(dp[count_song][count_unique]!=-1)
            return dp[count_song][count_unique];
        
        long long int op1=0,op2=0;

        if(count_unique<n)
            op1=(help(count_song+1,count_unique+1,goal,n,k,dp)%mod*(n-count_unique)%mod)%mod;     // picking up new song
        if(count_unique>k)
            op2=(help(count_song+1,count_unique,goal,n,k,dp)%mod*(count_unique-k)%mod)%mod;        // replaying a song

        return dp[count_song][count_unique]=(op1+op2)%mod;
    }

    int numMusicPlaylists(int n, int goal, int k) {
        vector<vector<long long int>> dp(goal+1,vector<long long int> (n+1,-1));
        return help(0,0,goal,n,k,dp);
    }
};
