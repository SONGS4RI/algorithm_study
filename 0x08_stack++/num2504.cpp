#include<bits/stdc++.h>
using namespace std;

int arr[16]={0,}, res=0; 
stack<pair<char,int>> st;
string s;
void func(char c1, int num, int i){
    if(!st.empty() && st.top().first == c1){
        if(i-st.top().second==1){
            arr[st.size()-1] += num;
        }
        else{
            arr[st.size()-1] += arr[st.size()]* num;
            arr[st.size()] = 0;
        }
        st.pop();
    }
    else{
        cout << 0;
        exit(0);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;
    for(int i=0;i<s.length();i++){
        if(s[i]=='('||s[i]=='[') st.push({s[i],i});
        else if(s[i]==')') func('(',2,i);
        else if(s[i]==']') func('[',3,i);
        if(st.empty()){
            res+=arr[0];
            arr[0] = 0;
        } 
    }
    cout << res;

    return 0;
}