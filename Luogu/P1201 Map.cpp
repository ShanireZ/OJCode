#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
map<string, int> cost; //該人的花費和收入統計
string name_list[15];  //名稱順序列表
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string str;
        cin >> str;
        name_list[i] = str;
        cost[str] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        string from;
        cin >> from;
        int cash, person;
        cin >> cash >> person;
        //計算該人的人均送禮花費
        if (person == 0)
        {
            cash = 0;
        }
        else
        {
            cash = cash / person;
        }
        cost[from] -= cash * person; //減去總花費
        for (int j = 1; j <= person; j++)
        {
            string name;
            cin >> name;
            cost[name] += cash; //加上收入
        }
    }
    for (int i = 1; i <= n; i++) //按輸入順序輸出
    {
        cout << name_list[i] << " " << cost[name_list[i]] << endl;
    }
    return 0;
}