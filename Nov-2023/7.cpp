// this is leetcode daily challenge of 7 Nov 2023
// problem link : https://leetcode.com/problems/eliminate-maximum-number-of-monsters/description/?envType=daily-question&envId=2023-11-07

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n=dist.size();
        vector<int> arrival(n);
        for(int i=0;i<n;i++)
        {
            if(dist[i]%speed[i]==0)
                arrival[i]=dist[i]/speed[i];
            else 
                arrival[i]=dist[i]/speed[i]+1;
        }

        sort(arrival.begin(),arrival.end());

        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(arrival[i]<=i)
                break;
            cnt++;
        }

        return cnt;
    }
};
