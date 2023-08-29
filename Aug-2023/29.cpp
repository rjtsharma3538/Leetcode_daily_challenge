// this is leetcode daily challenge of 29 Aug 2023
// problem link : https://leetcode.com/problems/minimum-penalty-for-a-shop/

class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.size();
        vector<int> v(n);
        
        int cnt=0;

        for(int i=0;i<n;i++)
        {
            v[i]=cnt;
            if(customers[i]=='N')
                cnt++;
            cout<<v[i]<<" ";
        }
        cout<<endl;

        int mini=cnt,ans=n;
        cnt=0;
        for(int i=n-1;i>=0;i--)
        {
            if(customers[i]=='Y')
                cnt++;
            v[i]+=cnt;
            if(mini>=v[i])
            {
                ans=i;
                mini=v[i];
            }
        }

        for(int i=0;i<n;i++)
            cout<<v[i]<<" ";
        cout<<endl;

        return ans;
    }
};
