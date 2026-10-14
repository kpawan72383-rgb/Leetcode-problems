
class LRUCache {
private:
    int cap;
    std::list<std::pair<int, int>> l;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> mp;
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }
        l.splice(l.begin(), l, mp[key]);
        return mp[key]->second;
    }
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            mp[key]->second = value;
            l.splice(l.begin(), l, mp[key]);
            return;
        }    
        if (l.size() == cap) {
            mp.erase(l.back().first);
            l.pop_back();
        } 
        l.push_front({key, value});
        mp[key] = l.begin();
    }
};
