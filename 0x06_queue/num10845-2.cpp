#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    queue<int> q;
    string s;
    int n,num;
    cin >> n;
    while(n--){
        cin >> s;
        if(s=="push"){
            cin >> num;
            q.push(num);
        }
        else if(s=="pop"){
            if(q.size()==0) cout << -1 << "\n";
            else{
                cout << q.front() << "\n";
                q.pop();
            }
        }
        else if(s=="size"){
            cout << q.size() << "\n";
        }
        else if(s=="empty"){
            cout << q.empty() << "\n";
        }
        else if(s=="front"){
            if(q.size()==0) cout << -1 << "\n";           
            else cout << q.front() << "\n";
        }
        else{
            if(q.size()==0) cout << -1 << "\n";
            else cout << q.back() << "\n";
        }
    }
    return 0;
}