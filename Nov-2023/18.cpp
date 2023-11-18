// this is leetcode daily challenge of 18 Nov 2023
// problem link : https://leetcode.com/problems/frequency-of-the-most-frequent-element/?envType=daily-question&envId=2023-11-18

class Solution {
public:

    void sorted(vector<int> &nums)
    {
        int maxi=0;
        for(auto it:nums)
            maxi=max(it,maxi);
        
        vector<int> freq(maxi+1,0);
        for(auto it:nums)
            freq[it]++;
        
        int i=0;
        for(int j=0;j<=maxi;j++)
        {
            while(freq[j]>0)
            {
                nums[i++]=j;
                freq[j]--;
            }
        }
    }

    int maxFrequency(vector<int>& nums, int k) {
        sorted(nums);
        long long int i=0,j=0,sum=0,diff;
        long long int max_len=0;

        while(j<nums.size())
        {
            sum+=nums[j];
            diff=nums[j]*(j-i+1)-sum;

            if(diff<=k)
            {
                if(j-i+1>max_len)
                {
                    max_len=j-i+1;
                }
                j++;
            }

            else 
            {
                while(diff>k)
                {
                    sum-=nums[i];
                    i++;
                    diff=nums[j]*(j-i+1)-sum;
                }

                if(j-i+1>max_len)
                {
                    max_len=j-i+1;
                }
                j++;

            }
        }

        return (int)max_len;
    }
};
