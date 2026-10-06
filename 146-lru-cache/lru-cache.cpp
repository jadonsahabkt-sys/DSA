class LRUCache {
    int cap;
    list<pair<int,int>> d11;
    unordered_map<int,list<pair<int,int>>::iterator>mp;
public:
    LRUCache(int capacity) : cap(capacity) {
        
    }
    
    int get(int key) {
        auto it =mp.find(key);
        if(it == mp.end()) return -1;
        d11.splice(d11.begin(),d11,it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {
        auto it = mp.find(key);
        if(it!=mp.end()){
            it->second->second=value;
            d11.splice(d11.begin(),d11,it->second);
            return;
        }
        if((int)d11.size()==cap){
            mp.erase(d11.back().first);
            d11.pop_back();
        }
        d11.push_front({key,value});
        mp[key]=d11.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */