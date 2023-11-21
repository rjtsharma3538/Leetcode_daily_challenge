// this is leetcode daily challenge of 21 Nov 2023
// problem link : https://leetcode.com/problems/count-nice-pairs-in-an-array/?envType=daily-question&envId=2023-11-21

class Solution {
public:

    int revsum(int num)
    {
        string s=to_string(num);
        reverse(s.begin(),s.end());
        num=stoi(s);
        return num;
    }

    int countNicePairs(vector<int>& nums) {
        unordered_map<int,int> mp;
        int cnt=0,mod=1e9+7;
        for(auto it:nums)
        {
            int sum=it;
            int rev=revsum(sum);

            if(mp.find(sum-rev)!=mp.end())
                cnt=(cnt+mp[sum-rev])%mod;
            mp[sum-rev]++;
        }

        return cnt;
    }
};
