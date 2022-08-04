#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    stack<pair<int,int>> st;
    int num;
    long long  cnt_pair=0;

    for(int i=0;i<n;i++){
        cin >> num;
        int cnt_same_height=1;
        while(!st.empty() && st.top().first<num){
            cnt_pair += st.top().second;
            st.pop();
        }
        if(!st.empty()){
            if(num==st.top().first){
                cnt_pair += st.top().second;
                cnt_same_height = st.top().second +1;
                if(st.size()>1) cnt_pair++;
                st.pop();
            }
            else{
                cnt_pair++;
            }
        }
        st.push(pair<int,int>(num,cnt_same_height));

    }
    cout << cnt_pair;
    return 0;
}