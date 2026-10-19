class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(),nums.end());
        int q=queries.size();
        vector<int> order(q);
        iota(order.begin(),order.end(),0);
        sort(order.begin(),order.end(),[&](int a,int b){
            return queries[a][1]<queries[b][1];
        });
        vector<array<int,2>> t;
        t.reserve(nums.size()*30+1);
        t.push_back({0,0});
        auto insert=[&](int x){
            int cur=0;
            for(int b=29;b>=0;b--){
                int bit=(x>>b) &1;
                if(!t[cur][bit]){
                  t[cur][bit]=t.size();
                  t.push_back({0,0});
                }
                cur=t[cur][bit];
            }
        };
        auto query=[&](int x){
            int cur=0,val=0;
            for(int b=29;b>=0;b--){
                int bit=(x>>b)&1;
                int want=bit^1;
                if(t[cur][want]){
                    val|=(1<<b);
                    cur=t[cur][want];
                }else{
                    cur=t[cur][bit];
                }
            }
            return val;
        };
        vector<int>ans(q,-1);
        int j=0,n=nums.size();
        for(int idx:order){
            int x=queries[idx][0],m=queries[idx][1];
            while(j<n && nums[j]<=m) insert(nums[j++]);
            if(j>0) ans[idx] =query(x);
        }
       return ans;
    }
};