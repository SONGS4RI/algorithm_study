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
        for(auto c : s){
            if(!st.empty() && st.top() != c){
                st.pop();
            }
            else if(st.empty() && c == ')'){
                st.push(c);
                break;
            }
            else st.push(c);
        }
        if(st.empty()) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
    
    return 0;
}