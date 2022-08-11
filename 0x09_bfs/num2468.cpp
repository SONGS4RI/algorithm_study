#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,arr[101][101],rain_min = 101,rain_max=0,res=0,nx,ny;
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    bool vis[101][101];
    queue<pair<int,int>> q;

    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
            if(arr[i][j]>rain_max) rain_max = arr[i][j];
            if(arr[i][j]<rain_min) rain_min = arr[i][j];
        }
    }

    for(int i=rain_min;i<rain_max;i++){
        int cnt = 0;
        for(int j=0;j<n;j++) fill(vis[j],vis[j]+n,false);
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                if(arr[j][k]>i && !vis[j][k]){
                    q.push({j,k});
                    vis[j][k] = 1;
                    while(!q.empty()){
                        auto cur = q.front();
                        q.pop();
                        for(int c=0;c<4;c++){
                            nx = cur.first + dx[c];
                            ny = cur.second + dy[c];
                            if(nx<0 || ny<0 || nx>=n || ny>=n) continue;
                            if(arr[nx][ny]<=i || vis[nx][ny]) continue;
                            vis[nx][ny] = 1;
                            q.push({nx,ny});
                        }
                    }
                    cnt++;
                }
            }
        }
        res = max(res,cnt);
    }
    if(rain_max==rain_min) cout << 1;
    else cout << res;
    
    return 0;
}