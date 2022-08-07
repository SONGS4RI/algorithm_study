#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m,n,maze[101][101],cnt_min=1;
    string s;
    queue<pair<int,int>> qu;
    int dist[101][101];
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> s;
        for(int j=1;j<=m;j++){
            maze[i][j] = (int)s[j-1]-48;
        }
    }
    for(int i=1;i<=n;i++) fill(dist[i],dist[i]+m,-1);
    qu.push({1,1});
    while(!qu.empty()){
        pair<int,int> cur = qu.front();
        qu.pop();
        for(int i=0;i<4;i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx<1 || nx>n || ny<1 || ny>m) continue;
            if(dist[nx][ny]>=0 || maze[nx][ny]!=1) continue;
            dist[nx][ny] = dist[cur.first][cur.second]+1;
            qu.push({nx,ny});
        }
        
    }
    cout << dist[n][m]+1;
    return 0;
}