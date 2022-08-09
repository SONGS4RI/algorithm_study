#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t,m,n,k,arr[51][51],nx,ny;
    bool visited[51][51];
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    cin >> t;
    while(t--){
        for(int i=0;i<51;i++){
            fill(visited[i],visited[i]+51,false);
            fill(arr[i],arr[i]+51,0);
        }
        int cnt = 0;
        cin >> m >> n >> k;
        for(int i=0;i<k;i++){
            cin >> nx >> ny;
            arr[ny][nx] = 1;
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]==1 && !visited[i][j]){
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    visited[i][j] = 1;
                    while(!q.empty()){
                        auto cur = q.front();
                        q.pop();
                        for(int k=0;k<4;k++){
                            nx = cur.first + dx[k];
                            ny = cur.second + dy[k];
                            if(nx<0|| ny<0 || nx >= n || ny >= m) continue;
                            if(visited[nx][ny] || arr[nx][ny]!=1) continue;
                            q.push({nx,ny});
                            visited[nx][ny] = 1; 
                        }
                    }
                    cnt++;
                }
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}