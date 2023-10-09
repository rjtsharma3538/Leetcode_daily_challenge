// this is leetcode daily challenge of 9 Oct 2023
// problem link : https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/?envType=daily-question&envId=2023-10-09

class Solution {
public:

    int first(vector<int> &nums, int target)
    {
        int s=0,e=nums.size()-1,ans=-1;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(nums[mid]==target)
            {
                e=mid-1;
                ans=mid;
            }
            else if(nums[mid]>target)
                e=mid-1;
            else 
                s=mid+1;
        }
        return ans;
    }

    int last(vector<int> &nums, int target)
    {
        int s=0,e=nums.size()-1,ans=-1;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(nums[mid]==target)
            {
                s=mid+1;
                ans=mid;
            }
            else if(nums[mid]<target)
                s=mid+1;
            else 
                e=mid-1;
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int fst=first(nums,target);
        if(fst==-1)
            return {-1,-1};
        int lst=last(nums,target);
        return {fst,lst};
    }
};
