class Solution {
public:
void dfs(vector<vector<int>>& grid,int r,int c){
    if(r<0 ||c<0 || r>=grid.size() || c>=grid[0].size()) return;
    if(grid[r][c]!=1) return;
    grid[r][c]=0;
    dfs(grid,r+1,c);
    dfs(grid,r-1,c);
    dfs(grid,r,c+1);
    dfs(grid,r,c-1);
}
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();

        for(int i=0;i<m;i++){
            dfs(grid,i,0);
            dfs(grid,i,n-1);
        }
        for(int j=0;j<n;j++){
            dfs(grid,0,j);
            dfs(grid,m-1,j);
        }
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                 count+=grid[i][j];
            }
        }
        return count;
    }
};