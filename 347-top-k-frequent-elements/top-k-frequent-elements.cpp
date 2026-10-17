class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>cnt;
        for(int x:nums) cnt[x]++;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        for(auto& [val,f]:cnt){
            pq.push({f,val});
            if(pq.size()>k) pq.pop();
        }
        vector<int> res;
        while(!pq.empty()){res.push_back(pq.top().second);pq.pop();}
       return res;
    }
};