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
        cin >> trash;
        if(n>0){
            while(n--){
            cin >> num >> trash;
            d.push_back(num);
            }
        }
        else cin >> trash;
        
        int flag = 0,err=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='R' && d.size()!=0) flag++;
            else if(d.size()==0 && s[i]=='D'){
                err = 1;
                break;
            }
            else if(s[i]=='D'){
                if(flag%2==0) d.pop_front();
                else d.pop_back();
            }
        }
        if(err==1) cout << "error\n";
        else{
            cout << "[";
            if(d.size()!=0){
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
                cout << d.front();
            }
            cout << "]\n";
        }
    }
    return 0;
}