#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int arr[n],res[n]={0,};
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    for(int i=n-1;i>0;i--){
        for(int j=i-1;j>=0;j--){
            if(arr[j]>=arr[i]){
                res[i] = j+1;
                break;
            }
            else res[i] = 0;
        }
    }
    for(int i=0;i<n;i++) cout << res[i] << " ";
    
    return 0;
}
// 아마 시간초과할것임 