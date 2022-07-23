#include<iostream>
#include<vector>
using namespace std;
// 시간복잡도 o(N)
int func1(int n)
{
    int sum=0;
    for(int i=3;i<=n;i++)
    {
        if(i%3==0 || i%5==0) sum+=i;
    }
    return sum;
}
int main()
{
    int n;
    cin >> n;
    cout << func1(n);
    
    return 0;
}