// this is leetcode daily challenge of 12 Oct 2023
// problem link : https://leetcode.com/problems/find-in-mountain-array/description/?envType=daily-question&envId=2023-10-12

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:

    int peak(int target, MountainArray &MountainArr)
    {
        int n=MountainArr.length();
        int s=1,e=n-2,mid;
        while(s<=e)
        {
            mid=s+(e-s)/2;
            if(MountainArr.get(mid)>MountainArr.get(mid-1)&&MountainArr.get(mid)>MountainArr.get(mid+1))
                return mid;
            else if(MountainArr.get(mid)<MountainArr.get(mid-1))
                e=mid-1;
            else 
                s=mid+1;
        }
        return -1;
    }

    int left(int target, MountainArray &v, int peak_idx)
    {
        int n=v.length();
        int s=0,e=peak_idx,mid;
        int ans=-1;

        while(s<=e)
        {
            mid=s+(e-s)/2;
            if(v.get(mid)==target)
            {
                ans=mid;
                e=mid-1;
            }
            else if(v.get(mid)<target)
                s=mid+1;
            else
                e=mid-1;
        }
        return ans;
    }

    int right(int target, MountainArray &v, int peak_idx)
    {
        int n=v.length();
        int s=peak_idx+1,e=n-1,mid;
        int ans=-1;

        while(s<=e)
        {
            mid=s+(e-s)/2;
            if(v.get(mid)==target)
            {
                ans=mid;
                e=mid-1;
            }
            else if(v.get(mid)<target)
                e=mid-1;
            else 
                s=mid+1;
        }
        return ans;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peak_idx=peak(target,mountainArr);
        if(target>mountainArr.get(peak_idx))
            return -1;
        cout<<peak_idx<<endl;
        int fst=left(target,mountainArr,peak_idx);
        if(fst!=-1)
            return fst;
        int sec=right(target,mountainArr,peak_idx);
        return sec;
    }
};
