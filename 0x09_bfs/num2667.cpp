#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,nx,ny,cnt[314]={0,},num=0;
    string apt[25];
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    
    bool visited[26][26];
    queue<pair<int,int>> q;
    cin >> n;
    for(int i=0;i<n;i++){
        fill(visited[i],visited[i]+n,false);
        cin >> apt[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(apt[i][j]=='1' && !visited[i][j]){
                q.push({i,j});
                visited[i][j]=1;
                while(!q.empty()){
                    auto cur = q.front();
                    q.pop();
                    for(int k=0;k<4;k++){
                        nx = cur.first + dx[k];
                        ny = cur.second + dy[k];
                        if(nx<0 || ny<0 || nx>= n || ny>= n) continue;
                        if(visited[nx][ny] || apt[nx][ny]!='1') continue;
                        visited[nx][ny] = 1;
                        q.push({nx,ny});
                    }
                    cnt[num]++;                    
                }
                num++;
            }
        }
    }
    sort(cnt,cnt+num);
    cout << num << "\n";
    for(int i=0;i<num;i++) cout << cnt[i] <<"\n";
    return 0;
}