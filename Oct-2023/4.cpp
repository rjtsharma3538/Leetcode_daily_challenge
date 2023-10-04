// this is leetcode daily challenge of 4 Oct 2023
// problem link : https://leetcode.com/problems/design-hashmap/?envType=daily-question&envId=2023-10-04

class MyHashMap {
public:

    vector<int> hash;
    MyHashMap() {
        int n=1e6;
        hash.resize(n+1,-1);
    }
    
    void put(int key, int value) {
        hash[key]=value;
    }
    
    int get(int key) {
        return hash[key];
    }
    
    void remove(int key) {
        hash[key]=-1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
