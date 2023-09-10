// this is leetcode daily challenge of 10 Sept 2023
// problem link : https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/description/?envType=daily-question&envId=2023-09-10

class Solution {
public:
    int countOrders(int n) {
        long int ans=1,num=2*n;
        int mod=1e9+7;
        for(int i=1;i<=n;i++)
        {
            ans=(ans*i)%mod;
            ans=(ans*(2*i-1))%mod;
        }

        return ans;
    }
};
