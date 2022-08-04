#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,num;
    long long cnt=0;
    stack<pair<int,int>> st;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> num;
        int same_height_cnt=1;
        while(!st.empty()&&st.top().first<num){
            cnt += st.top().second;
            st.pop();
        }
        if(!st.empty()){
            if(st.top().first==num){
                cnt +=st.top().second;
                same_height_cnt = st.top().second +1;
                if(st.size()>1) cnt++;
                st.pop();
            }
            else cnt++;
        }
        st.push(pair<int,int>(num,same_height_cnt));
    }
    cout << cnt;
    return 0;
}