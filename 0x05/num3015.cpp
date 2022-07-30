#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    stack<int> st;
    int n,num,flag=2;
    long long cnt=0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> num;
        while(!st.empty()){
            if(num>st.top()){
                st.pop();
                flag=1;
                cnt++;
            }
            else if(num==st.top()){
                cnt+=flag++;
                break;
            }
            else{
                flag=2;
                cnt++;
                break;
            }
        }
        st.push(num);
    }
    cout << cnt;

    return 0;
}
