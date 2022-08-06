#include<bits/stdc++.h>
using namespace std;
void func(){

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    int arr[16]={0,}, res=0; 
    stack<pair<char,int>> st;

    cin >> s;
    for(int i=0;i<s.length();i++){
        if(s[i]=='('||s[i]=='[') st.push({s[i],i});
        else if(s[i]==')'){
            if(!st.empty() && st.top().first =='('){
                if(i-st.top().second==1){
                    arr[st.size()-1] +=2;
                }
                else{
                    arr[st.size()-1] += arr[st.size()]*2; 
                }
                st.pop();
            }
            else{
                cout << 0;
                exit(0);
            }
        }
    }

    return 0;
}