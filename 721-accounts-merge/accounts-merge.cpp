class DSU {
    public:
         vector<int>parent,rnk;
         DSU(int n) : parent(n),rnk(n,0){
            iota(parent.begin(),parent.end(),0);
         }
         int find(int x){
            if(parent[x] != x) parent[x]=find(parent[x]);
            return parent[x];
         }
         void unite(int a,int b){
            a=find(a);b=find(b);
            if(a==b) return;
            if(rnk[a] <rnk[b]) swap(a,b);
            parent[b]=a;
            if(rnk[a] == rnk[b]) rnk[a]++;
         }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        DSU dsu(n);
        unordered_map<string,int> emailToId;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                const string& email=accounts[i][j];
                if(emailToId.count(email)){
                    dsu.unite(i,emailToId[email]);
                } else {
                    emailToId[email]=i;
                }
            }
        }
        unordered_map<int,set<string>> groups;
        for(auto& [email,id] : emailToId){
            groups[dsu.find(id)].insert(email);
        }
        vector<vector<string>> res;
        for(auto& [root,emails] : groups){
            vector<string> cur;
            cur.push_back(accounts[root][0]);
            cur.insert(cur.end(),emails.begin(),emails.end());
            res.push_back(cur);
        }
        return res;
    }
};