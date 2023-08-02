#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;
#define MX 10005
struct Node
{
    int dfn, low, g, v;
};
Node ns[MX];
struct Scc
{
    int p, maxp, ind;
};
Scc scc[MX];
int pos, gpos, ans;
stack<int> s;
vector<int> to[MX];
set<int> sccto[MX];
queue<int> q;
void tarjan(int now)
{
    ns[now].dfn = ns[now].low = ++pos;
    s.push(now);
    for (int nxt : to[now])
    {
        if (ns[nxt].dfn == 0)
        {
            tarjan(nxt);
            ns[now].low = min(ns[now].low, ns[nxt].low);
        }
        else if (ns[nxt].g == 0)
        {
            ns[now].low = min(ns[now].low, ns[nxt].dfn);
        }
    }
    if (ns[now].low == ns[now].dfn)
    {
        ++gpos;
        while (s.top() != now)
        {
            ns[s.top()].g = gpos;
            s.pop();
        }
        ns[s.top()].g = gpos;
        s.pop();
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> ns[i].v;
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        to[u].push_back(v);
    }
    for (int i = 1; i <= n; i++)
    {
        if (ns[i].dfn == 0)
        {
            tarjan(i);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int gnow = ns[i].g;
        scc[gnow].p += ns[i].v, scc[gnow].maxp += ns[i].v;
        for (int nxt : to[i])
        {
            int gnxt = ns[nxt].g;
            if (gnow != gnxt)
            {
                sccto[gnow].insert(gnxt);
            }
        }
    }
    for (int i = 1; i <= gpos; i++)
    {
        for (int j : sccto[i])
        {
            scc[j].ind++;
        }
    }
    for (int i = 1; i <= gpos; i++)
    {
        if (scc[i].ind == 0)
        {
            q.push(i);
        }
    }
    while (q.size())
    {
        int now = q.front();
        q.pop(), ans = max(ans, scc[now].maxp);
        for (int nxt : sccto[now])
        {
            scc[nxt].maxp = max(scc[nxt].maxp, scc[now].maxp + scc[nxt].p);
            if (--scc[nxt].ind == 0)
            {
                q.push(nxt);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}