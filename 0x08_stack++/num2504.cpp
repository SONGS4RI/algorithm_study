#include<bits/stdc++.h>
using namespace std;
void func(){

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    int arr[16]={0,}, cnt=0, res=0; // 
    stack<pair<char,int>> st;

    cin >> s;
    for(int i=0;i<s.length();i++){
        if(s[i]=='('||s[i]=='[') st.push({s[i],i});
        else if(s[i]==')'){
            if(!st.empty() && st.top()=='('){
                if(st.size()>1){
                    if(i-st.top().second==1) temp1+=2;
                    else temp1 *=2;
                }
                else if(i-st.top().second==1){
                    res += 2;
                }
                else{
                    res = temp1*2;
                }
            }
            else{
                cout << 0;
                exit(0);
            }
        }
    }

    return 0;
}