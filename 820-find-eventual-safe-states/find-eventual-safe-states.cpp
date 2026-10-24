class Solution {
    bool isSafe(int u,vector<vector<int>> &graph,vector<int>& state){
        if(state[u]!=0) return state[u]==2;
        state[u]=1;
        for(int v: graph[u]){
            if(!isSafe(v,graph,state)) return false;
        }
        state[u]=2;
        return true;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> state(n,0),ans;
        for(int i=0;i<n;i++){
            if(isSafe(i,graph,state)) ans.push_back(i);
        }
        return ans;
    }
};