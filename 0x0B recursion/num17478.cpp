#include <bits/stdc++.h>
using namespace std;

string str[7] = {"��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n", "\"����Լ��� ������?\"\n", "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n", "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n", "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n", "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n", "��� �亯�Ͽ���.\n"};

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