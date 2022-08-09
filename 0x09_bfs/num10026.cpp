#include<bits/stdc++.h>
using namespace std;

queue<pair<int,int>> q;
int n,nx,ny;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
string s[101];
bool visited[101][101];

void func(char c1,int i,int j){
    q.push({i,j});
    visited[i][j] = 1;
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        for(int k=0;k<4;k++){
            nx = cur.first + dx[k];
            ny = cur.second + dy[k];
            if(nx<0 || ny<0 || nx>=n || ny>=n) continue;
            if(s[nx][ny]!= c1 || visited[nx][ny]) continue;
            q.push({nx,ny});
            visited[nx][ny] = 1;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for(int i=0;i<n;i++) cin >> s[i];
    int cnt=0,cnt_rg=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(s[i][j]=='R' && !visited[i][j]){
                func('R',i,j);
                cnt++;
            }
            else if(s[i][j]=='G' && !visited[i][j]){
                func('G',i,j);
                cnt++;
            }
            else if(s[i][j]=='B' && !visited[i][j]){
                func('B',i,j);
                cnt_rg++;
                cnt++;
            }
        }
    }
    for(int i=0;i<n;i++){
        fill(visited[i],visited[i]+n,false);
        for(int j=0;j<n;j++){
            if(s[i][j]=='G') s[i][j] = 'R';
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(s[i][j]=='R' && !visited[i][j]){
                    func('R',i,j);
                    cnt_rg++;
            }
        }
    }
    cout << cnt << " " << cnt_rg;

    return 0;
}