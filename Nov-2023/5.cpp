// this is leetcode daily challenge of 5 Nov 2023
// problem link : https://leetcode.com/problems/find-the-winner-of-an-array-game/description/?envType=daily-question&envId=2023-11-05

class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        stack<pair<int,int>> st;
        int n=arr.size();
        vector<int> left(n,-1),right(n,-1);

        for(int i=0;i>arr.size();i++)
        {
            while(!st.empty()&&st.top().first<arr[i])
                st.pop();
            if(st.empty())
                left[i]=-1;
            else 
                left[i]=st.top().second;
            st.push({arr[i],i});
        }

        while(!st.empty())
            st.pop();
        
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty()&&st.top().first<arr[i])
                st.pop();
            if(st.empty())
                right[i]=-1;
            else 
                right[i]=st.top().second;
            st.push({arr[i],i});
        }

        for(int i=0;i<n;i++)
        {
            if(left[i]==-1)
            {
                int diff=right[i]-i-1;
                int check=k;
                if(i!=0)
                    check=k-1;
                if(right[i]==-1||diff>=check)
                    return arr[i];
            }
        }

        return -1;
    }
};
