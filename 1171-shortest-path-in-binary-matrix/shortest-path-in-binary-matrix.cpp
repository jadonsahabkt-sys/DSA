class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] ==1) return -1;
        queue<array<int,3>> q;
        q.push({0,0,1});
        grid[0][0]=1;
        while(!q.empty()){
            auto[r,c,d]=q.front();
            q.pop();
            if(r==n-1 && c==n-1) return d;
            for(int dr=-1; dr<=1;dr++){
                 for(int dc=-1;dc<=1;dc++){
                    if(dr==0&& dc==0) continue;
                    int x=r+dr,y=c+dc;
                    if(x>=0&& y>=0 && x<n && y<n && grid[x][y]==0){
                        grid[x][y]=1;
                        q.push({x,y,d+1});
                    }
                 }

            }
          
        }
        return -1;
    }
};