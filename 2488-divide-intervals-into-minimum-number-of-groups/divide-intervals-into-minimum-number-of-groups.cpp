class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<pair<int,int>> events;
        for(auto& it : intervals){
            events.push_back({it[0],1});
            events.push_back({it[1]+1,-1});
        }
        sort(events.begin(),events.end());
        int cur=0,ans=0;
        for(auto& [pos,delta]:events){
            cur +=delta;
            ans=max(ans,cur);
        }
        return ans;
    }
};