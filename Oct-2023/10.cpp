// this is gfg problem of the day of 10 Oct 2023
// problem link : https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous/submissions/?envType=daily-question&envId=2023-10-10

class Solution {
public:
    int minOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> v;
        v.push_back(nums[0]);

        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]!=nums[i-1])
                v.push_back(nums[i]);
        }

        int ans=nums.size();
        int j=0;
        int n=nums.size();

        for(int i=0;i<v.size();i++)
        {
            while(j<v.size()&&v[j]-v[i]<=n-1)
                j++;
            cout<<i<<" "<<j<<endl;
            ans=min(ans,n-(j-i));
        }

        return ans;
    }
};
