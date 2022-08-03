#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,num;
    cin >> n;
    stack<pair<int,int>> st;
    for(int i=0;i<n;i++){
        cin >> num;
        while(!st.empty()){
            if(num<st.top().second){
                cout << st.top().first << " ";
                break;
            }
            else st.pop();
        }
        if(st.empty()) cout << 0 << " ";
        st.push(pair<int,int>(i+1,num));
    }
    return 0;
}