#include<bits/stdc++.h>
using namespace std;
int n,stu[100001],vis[100001],cur;
void run(int x){
    cur = x;
    while(true){
        vis[cur] = x;
        cur = stu[cur];
        if(vis[cur]==x){
            while(vis[cur]!=-1){
                vis[cur] = -1;
                cur = stu[cur];
            }
            return;
        }
        else if(vis[cur]!=0) return;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        cin >> n;
        fill(vis+1,vis+n+1,0);
        for(int i=1;i<=n;i++) cin >> stu[i];
        for(int i=1;i<=n;i++){
            if(vis[i]==0) run(i);
        }
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(vis[i]!=-1) cnt++;
        }
        cout << cnt << "\n";
    }
    return 0;
}