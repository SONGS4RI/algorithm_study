#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    int temp1=0,temp2=0,res=0;
    stack<pair<char,int>> st;

    cin >> s;
    for(int i=0;i<s.length();i++){
        if(s[i]=='(' || s[i]=='['){
            st.push({s[i],i});
            temp2 += temp1;
            temp1 =0;
        }
        else if(st.empty()){
            if(s[i]==')' || s[i]==']'){
                st.push({s[i],i});
                break;
            }
        }
        else if(!st.empty() && s[i]==')'){
            if(i-st.top().second==1 && st.top().first == '('){
                if(st.size()==1) res += 2;
                else temp1 += 2;
            }
            else if(st.top().first == '[') break;
            else if(st.size()==1 && st.top().first == '('){
                res += (temp1+temp2)*2;
                temp1 = 0;
                temp2 = 0;
            }
            else temp1 *= 2;
            st.pop();
            if(st.empty()) temp2 += temp1;
        }
        else if(!st.empty() && s[i]==']'){
            if(i-st.top().second==1 && st.top().first == '['){
                if(st.size()==1) res += 3;
                else temp1 += 3;
            }
            else if(st.top().first == '(') break;
            else if(st.size()==1 && st.top().first == '['){
                res += (temp1+temp2)*2;
                temp1 = 0;
                temp2 = 0;
            }
            else temp1 *= 3;
            st.pop();
        }
    }
    if(st.empty()) cout << res;
    else cout << 0;

    return 0;
}