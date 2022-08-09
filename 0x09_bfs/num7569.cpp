#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m,n,h,box[101][101][101],dist[101][101][101],nx,ny,nz;
    int dz[6] = {0,0,0,0,1,-1};
    int dx[6] = {1,0,-1,0,0,0};
    int dy[6] = {0,1,0,-1,0,0};
    queue<tuple<int,int,int>> q;
    
    cin >> m >> n >> h;
    for(int i=0;i<h;i++){
        for(int j=0;j<n;j++){
            fill(dist[i][j],dist[i][j]+m,-1);
            for(int k=0;k<m;k++){
                cin >> box[i][j][k];
                if(box[i][j][k]==1){
                    q.push({i,j,k});
                    dist[i][j][k]=0;
                }
            }
        }
    }
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        for(int i=0;i<6;i++){
            nz = get<0>(cur) + dz[i];
            nx = get<1>(cur) + dx[i];
            ny = get<2>(cur) + dy[i];
           
            if(nx<0 || ny<0 || nz<0 || nx>=n || ny >=m || nz >= h) continue;
            if(box[nz][nx][ny]!=0 || dist[nz][nx][ny]>=0) continue;
            dist[nz][nx][ny] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] +1;
            q.push({nz,nx,ny});
        }
    }
    int min_day = 0;
    for(int i=0;i<h;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                if(box[i][j][k]!=-1 && dist[i][j][k]==-1){
                    cout << -1;
                    return 0;
                }
                min_day = max(min_day,dist[i][j][k]); 
            }
        }
    }
    cout << min_day;
    return 0;
}