#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    stack<pair<char,int>> st;
    string s;
    int res = 0;
    cin >> s;
    for(int i=0;i<s.length();i++){
        if(!st.empty() && st.top().first != s[i]){
            if(i-st.top().second==1 && st.size()>1) res += st.size()-1;
            else if(i-st.top().second!=1) res++;
            st.pop();
        }
        else st.push({s[i],i});
    }
    cout << res;


    return 0;
}