#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    string s;
    cin >> t;
    while(t--){
        stack<char> st;
        cin >> s;
        for(int i=0;i<s.length();i++){
            if(!st.empty() && st.top() != s[i]){
                st.pop();
            }
            else if(st.empty() && s[i] == ')'){
                st.push(s[i]);
                break;
            }
            else st.push(s[i]);
        }
        if(st.empty()) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
    
    return 0;
}