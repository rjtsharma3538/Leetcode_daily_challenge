// this is leetcode daily challenge of 20 Sept 2023
// problem link : https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/submissions/?envType=daily-question&envId=2023-09-20

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
            sum+=nums[i];
        int k=sum-x;
        if(k<0)
            return -1;
        if(k==0)
            return n;
        int i=0,j=0,ans=0;
        sum=0;
        
        while(j<n)
        {
            sum+=nums[j];
            if(sum<k)
                j++;
            else if(sum==k)
            {
                ans=max(ans,j-i+1);
                j++;
            }
            else 
            {
                while(sum>k)
                {
                    sum-=nums[i];
                    i++;
                }
                if(sum==k)
                    ans=max(ans,j-i+1);
                j++;
            }
        }
        if(ans==0)
            return -1;
        return n-ans;
        
    }
};
