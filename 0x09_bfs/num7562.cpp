#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t,l,bx,by,board[301][301],nx,ny;
    int dx[8] = {-2,-1,1,2,2,1,-1,-2};
    int dy[8] = {1,2,2,1,-1,-2,-2,-1};
    
    cin >> t;
    while(t--){
        queue<pair<int,int>> q;
        cin >> l >> bx >> by;
        for(int i=0;i<301;i++) fill(board[i],board[i]+l,-1);
        q.push({bx,by});
        board[bx][by]=0;
        cin >> bx >> by;

        while(board[bx][by]==-1){
            auto cur = q.front();
            q.pop();
            for(int i=0;i<8;i++){
                nx = cur.first + dx[i];
                ny = cur.second + dy[i];
                if(nx<0 || ny<0 || nx>=l || ny>=l) continue;
                if(board[nx][ny]>=0) continue;
                board[nx][ny] = board[cur.first][cur.second] +1;
                q.push({nx,ny});
            }
        }
        cout << board[bx][by] << "\n";
    }

    return 0;
}