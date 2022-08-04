#include<bits/stdc++.h>
using namespace std;
int main()
{
    int k,num;
    stack<int> st;
    cin >> k;
    while(k--){
        cin >> num;
        if(num==0 && st.size()!=0) st.pop();
        else if(num!=0) st.push(num);
    }
    num=0;
    while(st.size()){
        num+=st.top();
        st.pop();
    }
    cout << num;
    return 0;
}