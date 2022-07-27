#include <iostream>
#include <set>
using namespace std;
struct Ans
{
    int a, b;
    bool operator<(const Ans na) const
    {
        if (a == na.a)
        {
            return b < na.b;
        }
        return a < na.a;
    }
};
set<Ans> ans;
struct Edge
{
    int from, to, pre;
};
Edge es[10005];
int n, m, cnt, pos, last[155], dfn[155], low[155], fa[155];
void addEdge(int u, int v, int eid)
{
    es[eid].pre = last[u];
    es[eid].from = u;
    es[eid].to = v;
    last[u] = eid;
}
void tarjan(int now)
{
    dfn[now] = low[now] = ++pos;
    for (int i = last[now]; i != 0; i = es[i].pre)
    {
        int t = es[i].to;
        if (dfn[t] == 0)
        {
            fa[t] = now;
            tarjan(t);
            low[now] = min(low[now], low[t]);
            if (low[t] > dfn[now])
            {
                int a = min(es[i].from, es[i].to), b = max(es[i].from, es[i].to);
                ans.insert(Ans{a, b});
            }
        }
        else if (fa[now] != t)
        {
            low[now] = min(low[now], dfn[t]);
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        addEdge(a, b, ++cnt);
        addEdge(b, a, ++cnt);
    }
    for (int i = 1; i <= n; i++)
    {
        if (dfn[i] == 0)
        {
            tarjan(i);
        }
    }
    for (auto it = ans.begin(); it != ans.end(); it++)
    {
        cout << it->a << " " << it->b << endl;
    }
    return 0;
}