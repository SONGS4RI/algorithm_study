#include<bits/stdc++.h>
using namespace std;
deque<int> d;
int n,m,num,res=0;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i=n;i>0;i--) d.push_front(i);
    for(int i=0;i<m;i++){
        cin >> num;
        if(d.front()!=num){
            int cnt =0;
            while(d.front()!=num){
                d.push_back(d.front());
                d.pop_front();
                cnt++;
            }
            res += min(cnt,(int)d.size()-cnt);
            d.pop_front();
        }
        else d.pop_front();
    }
    cout << res;
    
    return 0;
}