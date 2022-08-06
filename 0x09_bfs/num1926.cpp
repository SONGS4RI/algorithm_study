#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int m,n,arr[501][501],cnt=0,max_cnt=0,max_temp=1;
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    bool visited[501][501];
    queue<pair<int,int>> qu;
    cin >> m >> n;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++) cin >> arr[i][j];
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(arr[i][j]==1 && !visited[i][j]){
                visited[i][j] = 1;
                qu.push({i,j});
                while(!qu.empty()){
                    pair<int,int> temp = qu.front();
                    qu.pop();
                    for(int i=0;i<4;i++){
                        int nx = temp.x + dx[i];
                        int ny = temp.y + dy[i];
                        if(nx<1 || nx>m || ny<1 || ny>n) continue;
                        if(visited[nx][ny] || arr[nx][ny]!=1) continue;
                        visited[nx][ny] = 1;
                        qu.push({nx,ny});
                        max_temp++;
                    }
                }
                max_cnt = max(max_cnt,max_temp);
                max_temp = 1;
                cnt++;
            }
        }
    }
    cout << cnt << "\n" << max_cnt;
    return 0;
}