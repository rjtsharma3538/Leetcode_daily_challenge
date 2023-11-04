// this is leetcode daily challenge of 4 Nov 2023
// problem link : https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/description/?envType=daily-question&envId=2023-11-04

class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int maxi=0;
        for(auto it:left)
            maxi=max(maxi,it);
        for(auto it:right)
            maxi=max(maxi,n-it);
        return maxi;
    }
};
