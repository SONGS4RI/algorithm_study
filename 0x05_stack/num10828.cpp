#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,num;
    string s1;
    stack<int> st;
    cin >> n;
    while(n--){
        cin >> s1;
        if(s1=="push"){
            cin >> num;
            st.push(num);
        }
        else if(s1=="pop"){
            if(st.size()!=0){
                cout << st.top() << "\n";
                st.pop();
            }
            else cout << -1 << "\n";
        }
        else if(s1=="size") cout << st.size() << "\n";
        else if(s1=="empty"){
            if(st.size()!=0) cout << 0 << "\n";
            else cout << 1 << "\n";
        }
        else if(s1=="top")
        {
            if(st.size()!=0) cout << st.top() << "\n";
            else cout << -1 << "\n";
        } 
    }
    return 0;
}