#include<iostream>
#include<queue>

using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int r,c,time[1001][1001];
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    queue<pair<int,int>> qu;
    string maze[1001];

    cin >> r >> c;
    for(int i=0;i<r;i++){
        cin >> maze[i];
        fill(time[i],time[i]+c,-1);
        for(int j=0;j<c;j++){
            if(maze[i][j]=='J' || maze[i][j]=='F'){
                time[i][j] = 1;
                qu.push({i,j});
            }
        }
    }
    while(1){
        if(maze[qu.front().first][qu.front().second]=='F'){
            auto cur = qu.front();
            qu.pop();
            qu.push(cur);
        }
        else break;
    }

    while(!qu.empty()){
        auto cur = qu.front();
        qu.pop();
        if(cur.first==0 || cur.second==0 || cur.first == r-1 || cur.second == c-1){
            if(maze[cur.first][cur.second]=='j'){
                cout << time[cur.first][cur.second];
                return 0;
            }
        }
        for(int i=0;i<4;i++){
            int nx = cur.first+dx[i];
            int ny = cur.second+dy[i];
            
            if(nx<0 || ny<0 || nx>=r || ny>=c) continue;
            if(maze[nx][ny]=='#' || maze[nx][ny]=='F') continue;
            if(maze[cur.first][cur.second]=='F'){
                if(maze[nx][ny]=='J' || maze[nx][ny]=='.') maze[nx][ny] = 'F';
            }
            else if(maze[cur.first][cur.second]=='J' && maze[nx][ny]=='.'){
                maze[nx][ny] = 'J';
                time[nx][ny] = time[cur.first][cur.second] +1;
            }
            qu.push({nx,ny});
            if(nx==0 || ny==0 || nx == r-1 || ny == c-1){
                if(maze[nx][ny]=='J'){
                    cout << time[nx][ny];
                    return 0;
                }
            }
        }

    }
    cout << "IMPOSSIBLE";
    

}