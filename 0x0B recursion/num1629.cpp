#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long a,b,c,res=1;

    cin >> a >> b >> c;
    while(b--)
    {
        res = (res * a) % c;
    }
    cout << res << '\n';
}