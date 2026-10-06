class LFUCache {
    int cap,minFreq;
    unordered_map<int,pair<int,int>> kv;
    unordered_map<int,list<int>> fl;
    unordered_map<int,list<int>::iterator>pos;
    void touch(int key){
        int f=kv[key].second;
        fl[f].erase(pos[key]);
        if(fl[f].empty()) {
            fl.erase(f);
            if(minFreq==f) minFreq++;
        }
        kv[key].second=++f;
        fl[f].push_front(key);
        pos[key]=fl[f].begin();
    }
public:
    LFUCache(int capacity):cap(capacity),minFreq(0) {
        
    }
    
    int get(int key) {
        if(!kv.count(key)) return -1;
        touch(key);
        return kv[key].first;
    }
    
    void put(int key, int value) {
        if(cap==0) return;
        if(kv.count(key)){
            kv[key].first=value;
            touch(key);
            return;
        }
        if((int)kv.size()==cap){
            int evict = fl[minFreq].back();
            fl[minFreq].pop_back();
            if(fl[minFreq].empty()) fl.erase(minFreq);
            kv.erase(evict);
            pos.erase(evict);
        }
        kv[key]={value,1};
        fl[1].push_front(key);
        pos[key]=fl[1].begin();
        minFreq=1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */