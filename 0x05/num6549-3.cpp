#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(true){
        int n,h;
        long long ans=0;
        stack<pair<int,int>> st;
        cin >> n;
        if(n==0) break;
        for(int i=0;i<n;i++){
            cin >> h;
            int idx = i;
            while(!st.empty()&&st.top().first>=h){
                ans = max(ans,1LL*(i-st.top().second)*st.top().first);
                idx = st.top().second;
                st.pop();
            }
            st.push({h,idx});
        }
        while(!st.empty()){
            ans = max(ans,1LL*(n-st.top().second)*st.top().first);
            st.pop();
        }
        cout << ans << "\n";
    }
    return 0;
}