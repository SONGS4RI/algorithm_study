#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,dist[102][102];
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    string s[102];
    queue<pair<int,int>> qu;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> s[i];
        fill(dist[i],dist[i]+m,-1);
    }
    dist[0][0]=1;
    qu.push({0,0});
    while(!qu.empty()){
        auto cur = qu.front();
        qu.pop();
        for(int i=0;i<4;i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
            if(dist[nx][ny]>=0 || s[nx][ny]!='1') continue;
            dist[nx][ny] = dist[cur.first][cur.second]+1;
            qu.push({nx,ny});            
        }
    }
    cout << dist[n-1][m-1];
    

    return 0;
}