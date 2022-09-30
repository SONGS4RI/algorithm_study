#include <bits/stdc++.h>
using namespace std;

int n;
string board[64];

bool is_square(int n, int x, int y)
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(board[x][y] != board[x+i][y+j]) return false;
    return true;
}

void recur(int n, int x, int y)
{
    if(is_square(n,x,y))
    {
        cout << board[x][y];
        return;
    }
    cout << '(';
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            recur(n/2, x+n/2*i, y+n/2*j);
    cout << ')';
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=0; i<n;i++)
            cin >> board[i];
    recur(n,0,0);
    cout << '\n';
    return 0;
}