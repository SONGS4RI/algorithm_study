#include <bits/stdc++.h>
using namespace std;

int k;

void func(int n, int r, int c, int res)
{
    k = pow(2,n-1); // 2
    if(r < k && c >= k)
    {
        res += k*k;
        c -= k;
    }
    else if(r >= k && c < k)
    {
        res += 2*k*k;
        r -= k;
    }
    else if(r >= k && c >= k)
    {
        res += 3*k*k;
        c -= k;
        r -= k;
    }
    if(n==1)
    {
        cout << res << '\n';
        return;
    }
    func(n-1,r,c,res);
}

int main(void)
{
    int n,r,c;
    cin >> n >> r >> c;
    func(n,r,c,0);
}