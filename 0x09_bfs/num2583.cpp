#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,k,nx,ny,x1,y1,cnt[5001]={0,},temp=0;
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};   
    bool vis[101][101];
    queue<pair<int,int>> q;

    cin >> m >> n >> k;
    for(int i=0;i<k;i++){
        cin >> ny >> nx >> y1 >> x1;
        for(int j=nx;j<x1;j++){
            for(int l=ny;l<y1;l++){
                vis[j][l]=1;
            }
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(!vis[i][j]){
                q.push({i,j});
                vis[i][j]=1;
                while(!q.empty()){
                    auto cur = q.front();
                    q.pop();
                    for(int l=0;l<4;l++){
                        nx = cur.first + dx[l];
                        ny = cur.second + dy[l];
                        if(nx<0 || ny<0 || nx >=m || ny>=n) continue;
                        if(vis[nx][ny]) continue;
                        vis[nx][ny] = 1;
                        q.push({nx,ny});
                    }
                    cnt[temp]++;
                }
                temp++;
            }
        }
    }
    cout << temp << "\n";
    sort(cnt,cnt+temp);
    for(int i=0;i<temp;i++) cout << cnt[i] << " ";
    return 0;
}