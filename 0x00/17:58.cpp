#include<iostream>
#include<cmath>
using namespace std;
int func4(int n)
{
    int i=0;
    while(1)
    {
        if(pow(2,i)>n) break;
        else i++;
    }
    return pow(2,i-1);
}
int main()
{
    int n;
    cin >> n;
    cout << func4(n);
    return 0;
}