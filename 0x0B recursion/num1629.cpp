#include<bits/stdc++.h>
using namespace std;

long long func(long long a, long long b, long long c)
{
    long long res;
    if(b==1)
        return a % c;
    res = func(a,b/2,c);
    res = res * res % c;
    if(b%2 == 0)
        return res;
    return res * a % c;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long a,b,c,res;
    cin >> a >> b >> c;
    res = func(a,b,c);
    cout << res << '\n';
}