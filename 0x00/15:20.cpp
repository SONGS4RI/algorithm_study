#include<iostream>
using namespace std;
// O(N^2)
int func2(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]+arr[j]==100) return 1;
        }
    }
    return 0;
}
int main()
{
    int n,arr[1000];
    cin >> n;
    for(int i=0;i<n;i++) cin >> arr[i];
    cout << func2(arr,n);
    return 0;
}