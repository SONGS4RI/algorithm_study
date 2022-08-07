#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,day[1001][1001],box[1001][1001],res=0;
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    queue<pair<int,int>> qu;
    cin >> m >> n;
    for(int i=0;i<n;i++){
        fill(day[i],day[i]+m,-1);
        for(int j=0;j<m;j++){
            cin >> box[i][j];
            if(box[i][j]==1){
                qu.push({i,j});
                day[i][j] = 0;
            }
        }
    }
    while(!qu.empty()){
        auto cur = qu.front();
        qu.pop();
        for(int i=0;i<4;i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx<0 || ny<0 || nx>=n ||ny>=m) continue;
            if(day[nx][ny]>=0 || box[nx][ny]!=0) continue;
            day[nx][ny] = day[cur.first][cur.second] + 1;
            res = max(res,day[nx][ny]);
            qu.push({nx,ny});
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(day[i][j]==-1&&box[i][j]!=-1){
                cout << -1;
                exit(0);
            }
        }
    }
    cout << res;

    return 0;
}