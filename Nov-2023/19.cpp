// this is leetcode daily challenge of 19 Nov 2023
// problem link : https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal/description/?envType=daily-question&envId=2023-11-19

class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        vector<int> freq(1e5,0);
        for(auto it:nums)
            freq[it]++;
        
        int num=0,ans=0;
        for(auto it:freq)
        {
            if(it>0)
            {
                ans+=it*num;
                num++;
            }
        }

        return ans;
    }
};
