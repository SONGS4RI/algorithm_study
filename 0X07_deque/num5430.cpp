#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,num;
    char trash;
    string s;
    cin >> t;
    while(t--){
        deque<int> d;
        cin >> s >> n;
        for(int i=0;i<n;i++){
            cin >> trash >> num;
            d.push_back(num);
        }
        cin >> trash;
        int flag = 0,err=0;
        for(int i=0;i<s.length();i++){
            if(d.size()==0 && s[i]=='D'){
                err = 1;
                break;
            }
            if(s[i]=='R') flag++;
            else{
                if(flag%2==0) d.pop_front();
                else d.pop_back();
            }
        }
        if(err==1) cout << "error\n";
        else{
            cout << "[";
            if(flag%2==0){
                while(d.size()>1){
                    cout << d.front() << ",";
                    d.pop_front();
                }
            }
            else{
                while(d.size()>1){
                    cout << d.back() << ",";
                    d.pop_back();
                }
            }
            cout << d.front() << "]\n";
        }
    }
    return 0;
}