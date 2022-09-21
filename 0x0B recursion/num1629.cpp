#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long a,b,c,res=1;
    a = (long long)INT_MAX;
    b = (long long)INT_MAX;
    c = 4;
    // cin >> a >> b >> c;
    while(b--)
    {
        res = (res * a) % c;
    }
    cout << res << '\n';
}