#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct Node
{
    string name;
    int id, bg, work, lv;
};
Node ns[150];
int cnt[10] = {1, 2, 2, 4, 7, 25, 200};
string wk[10] = {"BangZhu", "FuBangZhu", "HuFa", "ZhangLao", "TangZhu", "JingYing", "BangZhong"};
bool cmp1(Node a, Node b)
{
    if (a.bg == b.bg)
    {
        return a.id < b.id;
    }
    return a.bg > b.bg;
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
    return a.work < b.work;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string w;
        cin >> ns[i].name >> w >> ns[i].bg >> ns[i].lv;
        ns[i].id = i;
        for (int j = 0; j <= 6; j++)
        {
            if (w == wk[j])
            {
                ns[i].work = j;
                break;
            }
        }
    }
    sort(ns + 1, ns + 1 + n, cmp1);
    int pos = 2;
    for (int i = 1; i <= n; i++)
    {
        if (ns[i].work <= 1)
        {
            continue;
        }
        ns[i].work = pos;
        cnt[pos]--;
        if (cnt[pos] == 0)
        {
            pos++;
        }
    }
    sort(ns + 1, ns + 1 + n, cmp2);
    for (int i = 1; i <= n; i++)
    {
        cout << ns[i].name << " " << wk[ns[i].work] << " " << ns[i].lv << endl;
    }
    return 0;
}