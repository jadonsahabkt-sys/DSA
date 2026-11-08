class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>>pq;
        dist[0][0]=grid[0][0];
        pq.push({grid[0][0],0,0});
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        while(!pq.empty()){
            auto[t,x,y]=pq.top();pq.pop();
            if(x==n-1&&y==n-1) return t;
            if(t>dist[x][y]) continue;
            for(int d=0;d<4;d++){
                int nx=x+dx[d],ny=y+dy[d];
                if(nx<0||ny<0|| nx>=n || ny>=n) continue;
                int nt=max(t,grid[nx][ny]);
                if(nt<dist[nx][ny]){
                    dist[nx][ny]=nt;
                    pq.push({nt,nx,ny});
                }
            }
        }
        return -1;
    }
};