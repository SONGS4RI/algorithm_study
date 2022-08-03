#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[1000001],res[1000001],n;
    stack<int> st;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i=0;i<n;i++) cin >> arr[i];
    for(int i=n-1;i>=0;i--){
        while(!st.empty()&&st.top()<=arr[i]){
            st.pop();    
        }
        if(st.empty()) res[i] = -1;
        else res[i] = st.top();

        st.push(arr[i]);
    }
    for(int i=0;i<n;i++) cout << res[i] << " ";
    return 0;
}