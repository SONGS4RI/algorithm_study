#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int l,r,c,nx=0,ny,nz,exit[3];
    int dist[31][31][31];
    char map[31][31][31];
    const int dz[6] = {1,-1,0,0,0,0};
    const int dx[6] = {0,0,1,0,-1,0};
    const int dy[6] = {0,0,0,1,0,-1};
    while(true){
        queue<tuple<int,int,int>> q;
        cin >> l >> r >> c;
        if(l==0 && r==0 && c==0) break;
        for(int i=0;i<l;i++){
            for(int j=0;j<r;j++){
                fill(dist[i][j],dist[i][j]+c,-1);
            }
        }
        for(int i=0;i<l;i++){
            for(int j=0;j<r;j++){
                for(int k=0;k<c;k++){
                    cin >> map[i][j][k];
                    if(map[i][j][k]=='S'){
                        dist[i][j][k] = 0;
                        q.push({i,j,k});
                    }
                    else if(map[i][j][k]=='E'){
                        exit[0]=i;
                        exit[1]=j;
                        exit[2]=k;
                    }
                }
            }
        }
        while(dist[exit[0]][exit[1]][exit[2]]==-1 && !q.empty()){
            auto cur = q.front();
            q.pop();
            for(int ax=0;ax<6;ax++){
                nz = get<0>(cur) + dz[ax];
                nx = get<1>(cur) + dx[ax];
                ny = get<2>(cur) + dy[ax];
                if(nx<0 || ny<0 || nz<0 || nz>=l || nx>=r || ny>=c) continue;
                if(dist[nz][nx][ny]>=0 || map[nz][nx][ny]=='#') continue;
                dist[nz][nx][ny] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] +1;
                q.push({nz,nx,ny});
            }
        }
        if(dist[exit[0]][exit[1]][exit[2]]==-1) cout << "Trapped!" << "\n";
        else cout << "Escaped in "<< dist[exit[0]][exit[1]][exit[2]] << " minute(s)."<< "\n";
    }

    return 0;
}