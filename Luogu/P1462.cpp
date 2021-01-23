#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
struct Line
{
    long long dis, to;
};
struct Node
{
    long long cost, d;
    bool in;
    vector<Line> ls;
};
Node ns[10005];
queue<int> pt;
long long n, m, b, l, r;
void SPFA(long long lim)
{
    for (int i = 1; i <= n; i++)
    {
        ns[i].d = LONG_LONG_MAX;
    }
    ns[1].d = 0;
    ns[1].in = 1;
    pt.push(1);
    while (pt.size())
    {
        int from = pt.front();
        ns[from].in = 0;
        pt.pop();
        for (int i = 0; i < ns[from].ls.size(); i++)
        {
            int to = ns[from].ls[i].to;
            long long dis = ns[from].ls[i].dis;
            if (ns[to].cost > lim || dis + ns[from].d > b) //该路线费用超过预计 或 血不够走该路线
            {
                continue;
            }
            if (dis + ns[from].d < ns[to].d)
            {
                ns[to].d = dis + ns[from].d;
                if (ns[to].in == 0)
                {
                    ns[to].in = 1;
                    pt.push(to);
                }
            }
        }
    }
}
int main()
{
    cin >> n >> m >> b;
    l = LONG_LONG_MAX, r = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> ns[i].cost;
        l = min(ns[i].cost, l);
        r = max(ns[i].cost, r);
    }
    l = max(max(ns[1].cost, ns[n].cost), l);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        Line tmp1, tmp2;
        tmp1.dis = tmp2.dis = w,
        tmp1.to = v, tmp2.to = u;
        ns[u].ls.push_back(tmp1);
        ns[v].ls.push_back(tmp2);
    }
    int trig = 1;
    while (l <= r) //二分最高单段费用
    {
        long long mid = (l + r) / 2;
        SPFA(mid);
        if (ns[n].d != LONG_LONG_MAX) //不超过lim费用可以到达
        {
            r = mid - 1;
            trig = 0; //有可行解
        }
        else
        {
            l = mid + 1;
        }
    }
    if (trig)
    {
        cout << "AFK";
    }
    else
    {
        cout << l;
    }
    return 0;
}