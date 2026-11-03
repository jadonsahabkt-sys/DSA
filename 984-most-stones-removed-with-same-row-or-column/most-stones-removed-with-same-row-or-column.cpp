class DSU{
    public:
         unordered_map<int,int> parent;
         int comps=0;
         int find(int x){
            if(!parent.count(x)){
                parent[x]=x;
                comps++;
            }
            if(parent[x]!=x) parent[x]=find(parent[x]);
            return parent[x];
         }
         void unite(int a,int b){
            a=find(a);b=find(b);
            if(a==b) return;
            parent[b]=a;
            comps--;
         }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        DSU dsu;
        for(auto& s: stones){
            dsu.unite(s[0],s[1]+10001);
        }
        return stones.size()-dsu.comps;
    }
};