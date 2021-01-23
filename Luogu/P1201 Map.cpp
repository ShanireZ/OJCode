#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
map<string, int> cost; //该人的花费和收入统计
string name_list[15];  //名称顺序列表
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
        //计算该人的人均送礼花费
        if (person == 0)
        {
            cash = 0;
        }
        else
        {
            cash = cash / person;
        }
        cost[from] -= cash * person; //减去总花费
        for (int j = 1; j <= person; j++)
        {
            string name;
            cin >> name;
            cost[name] += cash; //加上收入
        }
    }
    for (int i = 1; i <= n; i++) //按输入顺序输出
    {
        cout << name_list[i] << " " << cost[name_list[i]] << endl;
    }
    return 0;
}