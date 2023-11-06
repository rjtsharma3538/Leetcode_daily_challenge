// this is leetcode daily challenge of 6 Nov 2023
// problem link : https://leetcode.com/problems/seat-reservation-manager/description/?envType=daily-question&envId=2023-11-06

class SeatManager {
public:

    set<int> res,un;
    SeatManager(int n) {
        for(int i=1;i<=n;i++)
            res.insert(i);
    }
    
    int reserve() {
        int num=*(res.begin());
        res.erase(num);
        return num;
    }
    
    void unreserve(int seatNumber) {
        res.insert(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
