#include<iostream>
#include<cmath>
using namespace std;
int func3(int n)
{
    if((int)pow((int)sqrt(n),2)==n) return 1;
    else return 0;
}
int main()
{
    int n;
    cin >> n;    
    cout << func3(n);
    return 0;
} 