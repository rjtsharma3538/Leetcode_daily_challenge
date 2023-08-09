// this is leetcode daily challenge of 9 Aug 2023
// problem link : https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/description/

class Solution {
public:

    bool help(vector<int>& nums, int mid, int p)
    {
        int cnt=0,i=1;
        while(i<nums.size())
        {
            if(nums[i]-nums[i-1]<=mid)
            {
                cnt++;
                i+=2;
            }
            else 
                i++;
            if(cnt>=p)
                return true;
        }
        return false;
    }

    int minimizeMax(vector<int>& nums, int p) {
        int mini=INT_MAX,maxi=INT_MIN;
        for(auto it:nums)
        {
            mini=min(mini,it);
            maxi=max(maxi,it);
        }

        int s=0,e=maxi-mini,ans=0;
        sort(nums.begin(),nums.end());
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(help(nums,mid,p))
            {
                ans=mid;
                e=mid-1;
            }
            else 
                s=mid+1;
        }
        return ans;
    }
};
