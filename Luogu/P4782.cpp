#include <iostream>
using namespace std;
#define MX 2000005
struct Edge
{
    int to, pre;
};
Edge es[MX];
struct Node
{
    int last, dfn, low, g;
};
Node ns[MX]; // 1~n真 n+1~2n假
int n, m, cnt, pos, gid, s[MX];
void addEdge(int u, int v, int eid)
{
    es[eid].to = v, es[eid].pre = ns[u].last;
    ns[u].last = eid;
}
void tarjan(int now)
{
    ns[now].low = ns[now].dfn = ++cnt;
    s[++pos] = now;
    for (int i = ns[now].last; i != 0; i = es[i].pre)
    {
        int to = es[i].to;
        if (ns[to].dfn == 0)
        {
            tarjan(to);
            ns[now].low = min(ns[now].low, ns[to].low);
        }
        else if (ns[to].g == 0)
        {
            ns[now].low = min(ns[now].low, ns[to].dfn);
        }
    }
    if (ns[now].dfn == ns[now].low)
    {
        gid++;
        while (now != s[pos])
        {
            ns[s[pos]].g = gid;
            pos--;
        }
        ns[now].g = gid;
        pos--;
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, a, y, b;
        cin >> x >> a >> y >> b;
        addEdge(x + n * (a & 1), y + n * (b ^ 1), i * 2 - 1); // x为非a,y必为b
        addEdge(y + n * (b & 1), x + n * (a ^ 1), i * 2);     // y为非b,x必为a
    }
    for (int i = 1; i <= n * 2; i++)
    {
        if (ns[i].dfn == 0)
        {
            tarjan(i);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (ns[i].g == ns[i + n].g)
        {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }
    cout << "POSSIBLE" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << (ns[i].g < ns[i + n].g) << " ";
    }
    return 0;
}