// this is leetcode daily challenge of 17 Nov 2023
// problem link : https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/description/?envType=daily-question&envId=2023-11-17

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0,j=nums.size()-1,ans=0;

        while(i<j)
        {
            ans=max(ans,nums[i]+nums[j]);
            i++;
            j--;
        }

        return ans;
    }
};
