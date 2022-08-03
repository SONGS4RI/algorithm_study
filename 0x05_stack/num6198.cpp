#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,num;
    long long cnt=0;
    cin >> n;
    stack<int> st;
    for(int i=0;i<n;i++){
        cin >> num;
        while(!st.empty()){
            if(num<st.top()){
                break;
            }
            else st.pop();
        }
        cnt+=st.size();
        st.push(num);
    }
    cout << cnt;
    return 0;
}