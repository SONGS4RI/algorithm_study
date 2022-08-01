#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,num,min=100001;
    stack<pair<int,int>> st;
    while(1){
        cin >> n;
        if(n==0) break;
        for(int i=0;i<n;i++){
            long long res=1;
            cin >> num;
            if(num<min) min = num;
            while(!st.empty()&&st.top().first+st.top().second<num){
                st.pop();
            }
            if(!st.empty()){
                if(st.top().first<=num){
                    res = st.top().first+st.top().second;
                }
                else{

                }
            }


            if(st.empty()) res *= num;
            st.push(pair<int,int>(num,res))
        }
        cout << res;
    }

    return 0;
}