#include <bits/stdc++.h>
using namespace std;

int a = 0, b=0, c=0, n;
int board[2187][2187] = {0,};

bool is_same(int n, int x, int y)
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            if(board[x][y] != board[x+i][y+j]) return false;
        }
    return true;
}

void recur(int n, int x, int y) // a = -1 cnt, b = 0 cnt , ....
{
    if(is_same(n,x,y))
    {
        if(board[x][y] == -1) a++;
        else if(board[x][y] == 0) b++;
        else c++;
        return;
    }
    // 9µîºÐ
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
        {
            recur(n/3, n/3*i, n/3*j)
        }
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> board[i][j]; 
   
    recur(n, 0, 0);
    cout << a << '\n' << b << '\n' << c << '\n';
    return 0;
}