#include<bits/stdc++.h>
using namespace std;

int n,arr[101][101],num[101][101],dist[101][101],island_num,res=201;
int island,nx,ny,flag=0;
const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,1,0,-1};
pair<int,int> cur;
queue<pair<int,int>> q;

void bfs(){
    island = 1;
    for(int i=0;i<n;i++) fill(num[i],num[i]+n,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]==1 && num[i][j]==0){
                num[i][j] = island;
                q.push({i,j});
                while(!q.empty()){
                    cur = q.front();
                    q.pop();
                    for(int dir=0;dir<4;dir++){
                        nx = cur.first + dx[dir];
                        ny = cur.second + dy[dir];
                        if(nx<0 || ny<0 || nx>=n || ny>=n) continue;
                        if(num[nx][ny]!=0 || arr[nx][ny]!=1) continue;
                        num[nx][ny] = island;
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
            fill(dist[i],dist[i]+n,-1);
            if(num[i][j]==0){
                for(int dir=0;dir<4;dir++){                    
                    nx = i + dx[dir];
                    ny = j + dy[dir];
                    if(num[nx][ny]!=0){
                        island_num = num[nx][ny];
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
                                if(num[nx][ny]!=0 && num[nx][ny]!=island_num){
                                    res = min(res,dist[cur.first][cur.second]);
                                    flag =1;
                                    break;
                                }
                                if(num[nx][ny]!=0) continue;
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