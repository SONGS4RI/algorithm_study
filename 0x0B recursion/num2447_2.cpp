#include <bits/stdc++.h>
using namespace std;
int n;

void star(int n, int i, int j)
{
    if((i/n)%3==1 && (j/n)%3==1)
        cout << " ";
    else
    {
        if(n == 1) cout << "*";
        else star(n/3,i,j);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=0;i<n;i++)
    {
        for(int j=0; j<n; j++)
            star(n,i,j);
        cout << "\n";
    }
    return(0);
}