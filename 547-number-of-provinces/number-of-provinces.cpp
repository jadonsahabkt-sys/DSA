class Solution {
    void dfs(int u,vector<vector<int>> & g,vector<bool>& vis){
        vis[u]=true;
        for(int v=0;v<(int)g.size();v++){
            if(g[u][v]&&!vis[v]) dfs(v,g,vis);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size(),provinces=0;
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,isConnected,vis);
                provinces++;
            }
        }
        return provinces;
    }
};