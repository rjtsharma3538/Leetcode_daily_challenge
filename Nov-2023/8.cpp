// this is leetcode daily challenge of 8 Nov 2023
// problem link : https://leetcode.com/problems/determine-if-a-cell-is-reachable-at-a-given-time/description/?envType=daily-question&envId=2023-11-08

class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if(sx==fx&&sy==fy)
        {
            if(t==1)
                return false;
            return true;
        }

        int tm=max(abs(fx-sx),abs(fy-sy));

        if(tm<=t)
            return true;
        return false;
    }
};
