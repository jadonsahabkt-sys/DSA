class Solution {
    vector<int> parent;
    int find(int x){
        if(parent[x]!=x) parent[x]=find(parent[x]);
        return parent[x];
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;
        parent.resize(n);
        iota(parent.begin(),parent.end(),0);
        int components=n;
        for(auto& c: connections){
            int a=find(c[0]),b=find(c[1]);
            if(a!=b){
                parent[a]=b;
                components--;
            }
        }
        return components-1;
    }
};