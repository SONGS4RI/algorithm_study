#include<iostream>
#include<list>
using namespace std;
int main(){
    int n;
    string str;
    char c[5];
    list<char> list1;
    auto cur = list1.end();
    cin >> str;
    for(int i=0;i<str.length();i++){
        list1.push_back(str[i]);
    }
    cin >> n;
    cin.ignore();
    while(n--){
        cin.getline(c,5);
        if(c[0]=='L' && cur!=list1.begin()) cur--;
        else if(c[0]=='D'&& cur!=list1.end()) cur++;
        else if(c[0]=='B' && cur!=list1.begin()){
            cur--;
            cur = list1.erase(cur);
        }
        else if(c[0]=='P') list1.insert(cur,c[2]);      
    }
    for(auto i : list1) cout << i ;
    cout << "\n";
    
    return 0;
}