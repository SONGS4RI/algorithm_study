#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,num=0,flag=0;
    cin >> n;
    int arr[n];
    vector<string> v;
    stack<int> st;
    for(int i=0;i<n;i++) cin >> arr[i];
    int i=0;
    st.push(num++);
    while(i<n){
        if(st.top()==arr[i]){
            v.push_back("-");
            st.pop();
            i++;
        }
        else if(st.top()!=arr[i] && num<=n){
            v.push_back("+");
            st.push(num++);
        }
        else{
            flag = 1;
            break;
        }
    }
    if(flag==1) cout << "NO";
    else{
        for(int i=0;i<v.size();i++) cout << v[i] << "\n";
    }

    return 0;
}