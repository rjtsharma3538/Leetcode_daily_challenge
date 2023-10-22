// this is leetcode daily challenge of 23 Oct 2023
// problem link : https://leetcode.com/problems/maximum-score-of-a-good-subarray/description/?envType=daily-question&envId=2023-10-22

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n=nums.size();
        stack<pair<int,int>> st;
        vector<int> left(n),right(n);

        for(int i=0;i<n;i++)
        {
            while(!st.empty()&&st.top().first>=nums[i])
                st.pop();
            if(st.empty())
                left[i]=-1;
            else 
                left[i]=st.top().second;
            st.push({nums[i],i});
        }

        while(!st.empty())
            st.pop();
        
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty()&&st.top().first>=nums[i])
                st.pop();
            if(st.empty())
                right[i]=n;
            else 
                right[i]=st.top().second;
            st.push({nums[i],i});
        }

        int ans=0;

        for(int i=0;i<n;i++)
        {
            int mini=nums[i];
            int len=right[i]-left[i]-1;

            if(k>left[i]&&k<right[i])
                ans=max(ans,mini*len);
        }

        return ans;
    }
};
