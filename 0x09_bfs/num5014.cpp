#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int f,s,g,u,d,arr[1000001],cur;
    queue<int> q;
    cin >> f >> s >> g >> u >> d;
    fill(arr,arr+f+1,-1);
    arr[s] = 0;
    q.push(s);
    while(!q.empty() && arr[g]==-1){
        cur = q.front();
        q.pop();
        for(int c : {cur+u,cur-d}){
            if(c<=0 || c>f)continue;
            if(arr[c]>=0) continue;
            arr[c] = arr[cur] +1;
            q.push(c);
        }
    }
    if(arr[g]!=-1) cout << arr[g];
    else cout << "use the stairs";
    return 0;
}