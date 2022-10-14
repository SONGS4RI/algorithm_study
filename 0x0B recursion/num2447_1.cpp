#include <bits/stdc++.h>
using namespace std;
int n;

void star(int n, int x, int y)
{
    if((x/n)%3 == 1 && (y/n)%3 == 1) cout << " ";
    else
    {
        if(n/3 == 0) cout << "*";
        else star(n/3,x,y);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            star(n,i,j);
        cout << "\n";
    }
    return (0);
}