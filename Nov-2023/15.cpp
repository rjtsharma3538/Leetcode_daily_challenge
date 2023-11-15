// this is leetcode daily challenge of 15 Nov 2023
// problem link : https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging/submissions/?envType=daily-question&envId=2023-11-15

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        arr[0]=1;
        int maxi=1;
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i]-arr[i-1]>1)
                arr[i]=arr[i-1]+1;
            maxi=max(maxi,arr[i]);
        }

        return maxi;
    }
};
