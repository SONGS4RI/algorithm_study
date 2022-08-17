#include<bits/stdc++.h>
using namespace std;
int ice[301][301],ice_temp[301][301],n,m,nx,ny,cnt,res=0;
bool vis[301][301];
const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,1,0,-1};
queue<pair<int,int>> q;
int bfs(){
    cnt =0;
    for(int i=0;i<n;i++){
        fill(vis[i],vis[i]+m,false);
    }
    for(int i=1;i<n-1;i++){
        for(int j=1;j<m-1;j++){
            if(ice[i][j]!=0 && !vis[i][j]){
                q.push({i,j});
                vis[i][j]=1;
                while(!q.empty()){
                    auto cur = q.front();
                    q.pop();
                    for(int dir=0; dir<4; dir++){
                        nx = cur.first + dx[dir];
                        ny = cur.second + dy[dir];
                        if(ice[nx][ny]==0 || vis[nx][ny]) continue;
                        q.push({nx,ny});
                        vis[nx][ny]=1;
                    }
                }
                cnt++;
            }
        }
    }
    if(cnt>1) return cnt;
    else if(cnt==0){
        cout << 0;
        exit(0);
    }
    else return 0;
}
void year(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) ice_temp[i][j] = ice[i][j];
    }
    for(int i=1;i<n-1;i++){
        for(int j=1;j<m-1;j++){
            if(ice_temp[i][j]!=0){
                cnt = 0;
                for(int dir=0; dir<4; dir++){
                    nx = i + dx[dir];
                    ny = j + dy[dir];
                    if(ice_temp[nx][ny]==0) cnt++;
                }
                if(ice_temp[i][j] < cnt) ice[i][j]=0;
                else ice[i][j] -= cnt;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin >> ice[i][j];
    }
    while(true){
        year();
        res++;
        if(bfs()>1) break;
    }
    cout << res;
    return 0;
}