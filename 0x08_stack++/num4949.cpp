#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    getline(cin,s,'.');
    while(s!=""){
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(s[i]== '('|| s[i]== ')'|| s[i]== '['|| s[i]== ']'){
                if(s[i]=='[') st.push('[');
                else if(s[i]=='(') st.push('(');
                else if(s[i]==')'){
                    if(st.empty() || st.top()!='('){
                        st.push(')');
                        break;
                    }
                    else if(st.top()=='(') st.pop();
                }
                else if(s[i]==']'){
                    if(st.empty() || st.top()!='['){
                        st.push(']');
                        break;
                    }
                    else if(st.top()=='[') st.pop();
                }
            }
        }
        if(st.empty()) cout << "yes" << "\n";
        else cout << "no" << "\n";
        cin.ignore();
        getline(cin,s,'.');
    }



    return 0;
}