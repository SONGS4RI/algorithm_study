#include<bits/stdc++.h>
using namespace std;
int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    stack<int> st;
    int n,num;
    cin >> n;
    int arr[n];
    vector<int> v;
    for(int i=0;i<n;i++){
        cin >> num;
        while(!st.empty()){
            if(st.top()<num){
                cout << num;
                st.pop();
                st.push(num);
            }
            else{
                st.push(num);
                break;
            }
        }
        if(st.empty()) st.push(num);
    }
    
    cout << -1;
    return 0;
}
st 5 1 
5 
4 5 1 2 3
5 -1 2 3 -1