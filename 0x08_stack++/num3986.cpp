#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,cnt=0;
    string s;
    cin >> n;
    while(n--){
        stack<char> st;
        cin >> s;
        for(int i=0;i<s.length();i++){
            if(!st.empty() && st.top()==s[i]){
                st.pop();
            }
            else st.push(s[i]);
        }
        if(st.empty()) cnt++;
    }
    cout << cnt;
    return 0;
}