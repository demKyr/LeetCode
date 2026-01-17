class RandomizedSet {
private:
    unordered_set<int> uset;
public:
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(uset.count(val))
            return false;
        uset.insert(val);
        return true;
    }
    
    bool remove(int val) {
        if(uset.count(val)){
            uset.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int randomIdx = rand() % uset.size();
        auto it = uset.begin();
        advance(it, randomIdx);
        return *it;   
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */