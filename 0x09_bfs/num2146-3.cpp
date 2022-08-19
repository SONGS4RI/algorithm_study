#include<bits/stdc++.h>
using namespace std;

int n,board[101][101],dist[101][101], nx, ny, idx=1,res=201;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
pair<int,int> cur;
queue<pair<int,int>> q;
void island_number(){
    while(!q.empty()) q.pop();
    for(int i=0;i<n;i++) fill(dist[i],dist[i]+n,0);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board[i][j]==1 && dist[i][j]==0){
                q.push({i,j});
                board[i][j]=idx;
                dist[i][j]=1;
                while(!q.empty()){
                    cur = q.front(); q.pop();
                    for(int dir=0;dir<4;dir++){
                        nx = cur.first + dx[dir];
                        ny = cur.second + dy[dir];
                        if(nx<0 || ny<0 || nx>=n || ny>=n) continue;
                        if(board[nx][ny]==0 || dist[nx][ny]!=0) continue;
                        q.push({nx,ny});
                        board[nx][ny] = idx;
                        dist[nx][ny] = 1;
                    }
                }
                idx++;
            }
        }
    }    
}
void melt(){
    for(int i=0;i<n;i++) fill(dist[i],dist[i]+n,0);
    while(!q.empty()) q.pop();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board[i][j]!=0){
                dist[i][j]=0;
                q.push({i,j});
            }
        }
    }

    while(!q.empty()){
        cur = q.front(); q.pop();
        for(int dir=0;dir<4;dir++){
            nx = cur.first + dx[dir];
            ny = cur.second + dy[dir];
            if(nx<0 || ny<0 || nx>=n || ny>=n) continue;
            if(board[nx][ny]==board[cur.first][cur.second] ) continue;
            if(board[nx][ny]!=0) res = min(res,dist[nx][ny]+dist[cur.first][cur.second]);
            else{
                board[nx][ny]=board[cur.first][cur.second];
                dist[nx][ny] = dist[cur.first][cur.second] +1;
                q.push({nx,ny});
            }
        }
    }    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cin >> board[i][j];
    }
    island_number();
    melt();    

    cout << res;

    return 0;
}