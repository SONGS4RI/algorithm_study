#include <iostream>
#include <cmath>
using namespace std;

void func(int a, int b, int n)
{
    if(n == 1)
    {
        cout << a << ' ' << b << '\n';
        return;
    }
    func(a, 6-a-b, n-1);
    cout << a << ' ' << b << '\n';
    func(6-a-b, b, n-1);
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,k;
    cin >> n;
    k = pow(2,n)-1;
    cout << k << '\n';
    func(1,3,n);
}
