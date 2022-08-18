#include<bits/stdc++.h>
using namespace std;

int n,arr[101][101],dist[101][101],res=201;
int island=1,nx,ny,flag=0;
const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,1,0,-1};
pair<int,int> cur;
queue<pair<int,int>> q;

void bfs(){
    for(int i=0;i<n;i++) fill(dist[i],dist[i]+n,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]==1 && dist[i][j]==0){
                arr[i][j] = island;
                dist[i][j] = 1;
                q.push({i,j});
                while(!q.empty()){
                    cur = q.front();
                    q.pop();
                    for(int dir=0;dir<4;dir++){
                        nx = cur.first + dx[dir];
                        ny = cur.second + dy[dir];
                        if(nx<0 || ny<0 || nx>=n || ny>=n) continue;
                        if(arr[nx][ny]!=1 || dist[nx][ny]!=0) continue;
                        arr[nx][ny] = island;
                        dist[nx][ny] = 1;
                        q.push({nx,ny});
                    }                    
                }
                island++;
            }
        }
    }
}

void bridge(){
    for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++) fill(dist[k],dist[k]+n,-1);
                if(arr[i][j]==0){
                    for(int dir=0;dir<4;dir++){                    
                        nx = i + dx[dir];
                        ny = j + dy[dir];
                        if(nx<0 || ny<0 || nx>=n || ny>=n) continue;
                        if(arr[nx][ny]!=0){
                            island = arr[nx][ny];
                            flag=0;
                            q.push({i,j});
                            dist[i][j]=1;
                            while(!q.empty()){
                                cur = q.front();
                                q.pop();
                                if(dist[cur.first][cur.second]>=res) break;
                                for(int dir=0;dir<4;dir++){
                                    nx = cur.first + dx[dir];
                                    ny = cur.second + dy[dir];
                                    if(nx<0 || ny<0 || nx>=n || ny>=n) continue;
                                    if(arr[nx][ny]!=0 && arr[nx][ny]!=island){
                                        res = min(res,dist[cur.first][cur.second]);
                                        flag =1;
                                        break;
                                    }
                                    if(dist[nx][ny]>=0 || arr[nx][ny]!=0) continue;
                                    dist[nx][ny] = dist[cur.first][cur.second] +1;
                                    q.push({nx,ny});
                                }     
                                if(flag==1) break;
                            }
                            while(!q.empty()) q.pop();
                            break;
                        }
                    }
                }
            }
        }    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cin >> arr[i][j];
    }
    bfs();
    bridge();
    
    cout << res;

    return 0;
}