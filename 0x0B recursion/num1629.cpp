#include<bits/stdc++.h>
using namespace std;

long long recur(long long a, long long b, long long c)
{
    long long res;
    if(b == 1) return a % c;
    res = recur(a,b/2,c);
    res = res * res % c;
    if(b % 2 == 0) return res;
    return res * res % c;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long a,b,c,res;

    a = b = INT_MAX;
    c = 5;
    // cin >> a >> b >> c;
    res = recur(a,b,c);
    cout << res << '\n';
}