#include<bits/stdc++.h>
using namespace std;
int n,m,dist[1001][1001][2],nx,ny;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
string board[1001];
int bfs(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            dist[i][j][0] = dist[i][j][1] = -1;                      
        }
    }
    dist[0][0][0] = dist [0][0][1] = 1;
    queue<tuple<int,int,int>> q;
    q.push({0,0,0});

    while(!q.empty()){
        int x,y,broken;
        tie(x,y,broken) = q.front();
        if(x==n-1 && y==m-1) return dist[x][y][broken];
        q.pop();
        int nextdist = dist[x][y][broken] +1;
        for(int i=0;i<4;i++){
            nx = x + dx[i];
            ny = y + dy[i];
            if(nx<0 || ny<0 || nx >= n || ny >= m) continue;
            if(board[nx][ny]=='0' && dist[nx][ny][broken]==-1){
                dist[nx][ny][broken] = nextdist;
                q.push({nx,ny,broken});
            }
            if(!broken && board[nx][ny]=='1' && dist[nx][ny][broken]==-1){
                dist[nx][ny][1] = nextdist;
                q.push({nx,ny,1});
            }
        }
    
    }
    return -1;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i=0;i<n;i++) cin >> board[i];
    cout << bfs();
    return 0;
}