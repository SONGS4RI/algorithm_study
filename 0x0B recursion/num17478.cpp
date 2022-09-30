#include <bits/stdc++.h>
using namespace std;

string str[7] = {"어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n", "\"재귀함수가 뭔가요?\"\n", "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n", "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n", "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n", "\"재귀함수는 자기 자신을 호출하는 함수라네\"\n", "라고 답변하였지.\n"};

void recur(int n, int bar)
{
    for(int j=0;j<bar;j++) cout << "____";
    cout << str[1];
    if(n == 0)
    {
        for(int j=0;j<bar;j++) cout << "____";
        cout << str[5];
        while(bar>=0)
        {
            for(int j=0;j<bar;j++) cout << "____";
            cout << str[6];
            bar--;
        }
        return;
    }
    for(int i=2;i<5;i++)
    {
        for(int j=0;j<bar;j++) cout << "____";
        cout << str[i];        
    }
    recur(n-1, bar+1);
}

int main(void)
{
    int n;
    cin >> n;
    if(n==0)
    {
        for(int i=0;i<7;i++) cout << str[i];
        return 0;
    }
    cout << str[0];
    recur(n,0);
    
}