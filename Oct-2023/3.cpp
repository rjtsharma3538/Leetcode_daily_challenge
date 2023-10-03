// this is leetcode daily challenge of 3 Oct 2023
// problem link : https://leetcode.com/problems/number-of-good-pairs/description/?envType=daily-question&envId=2023-10-03

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        map<int,int> mp;
        for(auto it:nums)
            mp[it]++;
        
        int ans=0;
        
        for(auto it:mp)
            ans+=((it.second)*(it.second-1))/2;

        return ans;
    }
};
