#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
struct Line
{
    int to, d;
};
struct Node
{
    int s, ind;
    vector<Line> ls;
};
Node ns[100005];
queue<int> pt;
//把每次挤奶看作点
//把前置关系看作边，边长为天数
//问题就转化为了 拓扑+SPFA最短路
int main()
{
    int n, m, c;
    cin >> n >> m >> c;
    for (int i = 1; i <= n; i++) //每个点都有个前置边
    {
        cin >> ns[i].s;
    }
    for (int i = 1; i <= c; i++)
    {
        int a, b, x;
        cin >> a >> b >> x;
        Line tmp;
        tmp.to = b, tmp.d = x;
        ns[a].ls.push_back(tmp);
        ns[b].ind++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (ns[i].ind == 0)
        {
            pt.push(i);
        }
    }
    while (pt.size())
    {
        int from = pt.front();
        pt.pop();
        for (int i = 0; i < ns[from].ls.size(); i++)
        {
            int to = ns[from].ls[i].to;
            int dto = ns[from].ls[i].d;
            ns[to].s = max(ns[to].s, ns[from].s + dto);
            ns[to].ind--;
            if (ns[to].ind == 0)
            {
                pt.push(to);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ns[i].s << endl;
    }
    return 0;
}