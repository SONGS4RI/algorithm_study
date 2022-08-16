#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int a;
    int* pt1, pt2;
    pt1 = &a;
    pt2 = a; // 포인터 아님
    a= 10;
    cout << *pt1;
    


    return 0;


}