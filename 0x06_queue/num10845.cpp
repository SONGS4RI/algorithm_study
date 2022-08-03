#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,arr[10001],head=0,tail=0,num;
    string s;
    cin >> n;
    while(n--){
        cin >> s;
        if(s=="push"){
            cin >> num;
            arr[tail++]=num;
        }
        else if(s=="pop"){
            if(tail==head) cout << -1 << "\n";
            else{
                cout << arr[head++] << "\n";
            }
        }
        else if(s=="size"){
            cout << tail-head << "\n";
        }
        else if(s=="empty"){
            if(tail==head) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
        else if(s=="front"){
            if(tail==head) cout << -1 << "\n";
            else cout << arr[head]<< "\n";;
        }
        else{
            if(tail==head) cout << -1 << "\n";
            else cout << arr[tail-1]<< "\n";;
        }
    }

    return 0;
}