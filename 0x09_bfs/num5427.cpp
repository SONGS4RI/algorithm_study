#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t,w,h,dist_sang[1001][1001],dist_fire[1001][1001],nx,ny;
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    string s[1001]; 

    cin >> t;
    while(t--){
        queue<pair<int,int>> q_sang,q_fire;
        int escape = 0;
        cin >> w >> h;
        for(int i=0;i<h;i++){
            cin >> s[i];
            fill(dist_sang[i],dist_sang[i]+w,-1);
            fill(dist_fire[i],dist_fire[i]+w,-1);
            for(int j=0;j<w;j++){
                if(s[i][j]=='@'){
                    q_sang.push({i,j});
                    dist_sang[i][j] = 0;
                }
                else if(s[i][j]=='*'){
                    q_fire.push({i,j});
                    dist_fire[i][j] = 0;
                }
            }
        }

        while(!q_fire.empty()){
            auto cur = q_fire.front();
            q_fire.pop();
            for(int i=0;i<4;i++){
                nx = cur.first + dx[i];
                ny = cur.second + dy[i];
                if(nx<0 || ny <0 || nx >= h || ny >= w) continue;
                if(dist_fire[nx][ny]>=0 || s[nx][ny] =='#') continue;
                dist_fire[nx][ny] = dist_fire[cur.first][cur.second] +1;
                q_fire.push({nx,ny});
            }
        }
        while(!q_sang.empty()){
            auto cur = q_sang.front();
            q_sang.pop();
            for(int i=0;i<4;i++){
                nx = cur.first + dx[i];
                ny = cur.second + dy[i];
                if(nx<0 || ny <0 || nx >= h || ny >= w){
                    cout << dist_sang[cur.first][cur.second] +1 << "\n";
                    escape = 1;
                    break;
                }
                if(dist_sang[nx][ny]>=0 || s[nx][ny] !='.') continue;
                if(dist_fire[nx][ny]!=-1 && dist_fire[nx][ny]<=dist_sang[cur.first][cur.second]+1) continue;
                dist_sang[nx][ny] = dist_sang[cur.first][cur.second] +1;
                q_sang.push({nx,ny});
                
            }
            if(escape==1) break;
        }
        if(escape==0) cout << "IMPOSSIBLE" << "\n";
        
        
    }

    return 0;
}