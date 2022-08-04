#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,num;
    string s;
    cin >> n;
    int arr[2*n+1],head=n,tail=n;
    while(n--){
        cin >> s;
        if(s=="push_front"){
            cin >> num;
            arr[head--]=num;
        }
        else if(s=="push_back"){
            cin >> num;
            arr[++tail]=num;
        }
        else if(s=="pop_front"){
            if(head==tail) cout << -1 << "\n";
            else cout << arr[head+++1] << "\n";
        }
        else if(s=="pop_back"){
            if(head==tail) cout << -1 << "\n";
            else cout << arr[tail--] << "\n";
        }
        else if(s=="size") cout << tail-head << "\n";
        else if(s=="empty") cout << (head==tail ? 1 : 0) << "\n";
        else if(s=="front") cout << (head==tail ? -1 : arr[head+1]) << "\n";
        else if(s=="back") cout << (head==tail ? -1 : arr[tail]) << "\n";        
    }

    return 0;
}