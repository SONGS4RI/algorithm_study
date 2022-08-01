#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,num,cnt=0;
    stack<pair<int,int>> st;
    for(int i=0;i<n;i++){
        cin >> num;
        int same_height_cnt=2;
        while(!st.empty()&&st.top()<num){
            cnt += st.top().second;
            st.pop();
        }
        if(!st.empty()){
            if(st.top==num){
                cnt +=st.top().second;
                
            }
        }
    }

    return 0;
}