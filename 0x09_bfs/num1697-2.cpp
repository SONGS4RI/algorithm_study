#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k,cur;
    int dist[100001];
    queue<int> q;
    fill(dist,dist+100001,-1);

    cin >> n >> k;
    q.push(n);
    dist[n]=0;
    while(dist[k]==-1){
        cur = q.front();
        q.pop();
        for(int i : {cur-1,cur+1,cur*2}){
            if(i<0 || i>100001) continue;
            if(dist[i]!=-1) continue;
            dist[i] = dist[cur]+1;
            q.push(i);
        }
    }
    cout << dist[k];
}