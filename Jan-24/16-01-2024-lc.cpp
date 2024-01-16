/*

Author : Atishay Gupta
Date : 16/01/2024
Problem : Insert Delete GetRandom O(1)
Difficulty : Medium
Problem Link : https://leetcode.com/problems/insert-delete-getrandom-o1/description/?envType=daily-question&envId=2024-01-16

*/

class RandomizedSet {
public:
    unordered_map<int,int> mp;
    vector<int> arr;
    RandomizedSet() {

    }
    
    bool insert(int val) {
       if(mp.find(val)!= mp.end()) return false;
        arr.push_back(val);
        mp[val] = arr.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val)==mp.end()) return false;
        int lst = arr[arr.size() - 1];
        int idx = mp[val];
        arr[idx] = lst;
        arr.pop_back();
        mp[lst] = idx;
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        return arr[rand()%mp.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */