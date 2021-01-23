#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
struct Node
{
    string name;
    int work, score, lv, id;
};
Node nodes[150];
string works[7] = {"BangZhong", "JingYing", "TangZhu", "ZhangLao", "HuFa", "FuBangZhu", "BangZhu"};
int all[7] = {150, 25, 7, 4, 2, 0, 0};
bool cmp1(Node a, Node b)
{
    if (a.score == b.score)
    {
        return a.id < b.id;
    }
    return a.score > b.score;
}
bool cmp2(Node a, Node b)
{
    if (a.work == b.work)
    {
        if (a.lv == b.lv)
        {
            return a.id < b.id;
        }
        return a.lv > b.lv;
    }
    return a.work > b.work;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string tmp;
        cin >> nodes[i].name >> tmp >> nodes[i].score >> nodes[i].lv;
        for (int j = 0; j < 7; j++)
        {
            if (works[j] == tmp)
            {
                nodes[i].work = j;
                break;
            }
        }
        nodes[i].id = i;
    }
    sort(nodes + 1, nodes + 1 + n, cmp1);
    int pos = 4;
    for (int i = 1; i <= n; i++)
    {
        if (nodes[i].work >= 5)
        {
            continue;
        }
        nodes[i].work = pos;
        all[pos]--;
        if (all[pos] == 0)
        {
            pos--;
        }
    }
    sort(nodes + 1, nodes + 1 + n, cmp2);
    for (int i = 1; i <= n; i++)
    {
        cout << nodes[i].name << " " << works[nodes[i].work] << " " << nodes[i].lv << endl;
    }
    return 0;
}