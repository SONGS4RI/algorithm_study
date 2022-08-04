#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,l,num;
    deque<pair<int,int>> dq;
    cin >> n >> l;
    for(int i=0;i<n;i++){
        cin >> num;
        while(dq.size()!=0 && dq.back().first >= num){
            dq.pop_back();
        }
        dq.push_back({num,i});
        if(dq.front().second<=i-l){
            dq.pop_front();
        }
        
        cout << dq.front().first << " ";
    }
    return 0;
}