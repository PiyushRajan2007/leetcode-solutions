
class LRUCache {
private:
    int cap;
    list<pair<int, int>> dll; 
    // front = most recently used, back = least recently used

    unordered_map<int, list<pair<int, int>>::iterator> mp;
    // key -> iterator pointing to node in list

public:
    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        // Key not found
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        // Move accessed node to front (most recently used)
        auto it = mp[key];
        int value = it->second;

        dll.erase(it);
        dll.push_front({key, value});
        mp[key] = dll.begin();

        return value;
    }

    void put(int key, int value) {
        // If key already exists, remove old node
        if (mp.find(key) != mp.end()) {
            dll.erase(mp[key]);
        }
        // If cache is full, remove least recently used item
        else if ((int)dll.size() == cap) {
            int lruKey = dll.back().first;
            dll.pop_back();
            mp.erase(lruKey);
        }

        // Insert new/updated node at front
        dll.push_front({key, value});
        mp[key] = dll.begin();
    }
};

