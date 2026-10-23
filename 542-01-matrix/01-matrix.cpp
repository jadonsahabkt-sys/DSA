class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        vector<vector<int>> dist(m,vector<int>(n,-1));
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] ==0){
                    dist[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        int dirs[4][2] ={{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()){
            auto[x,y]=q.front();
            q.pop();
            for(auto& d: dirs){
                int nx=x+d[0],ny=y+d[1];
                if(nx<0 ||ny<0 || nx>=m || ny>=n) continue;
                if(dist[nx][ny] !=-1) continue;
                dist[nx][ny]=dist[x][y]+1;
                q.push({nx,ny});
            }
        }
        return dist;
    }
};