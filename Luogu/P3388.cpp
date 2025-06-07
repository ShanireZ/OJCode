#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
#define MX 20005
vector<int> to[MX];
set<int> g;
int n, m, root, npos, dfn[MX], low[MX];
void tarjan(int now)
{
    dfn[now] = low[now] = ++npos;
    int chs = 0;
    for (int nxt : to[now])
    {
        if (dfn[nxt] == 0)
        {
            tarjan(nxt), chs++;
            low[now] = min(low[now], low[nxt]);
            if (now != root && low[nxt] >= dfn[now])
            {
                g.insert(now);
            }
        }
        else
        {
            low[now] = min(low[now], dfn[nxt]);
        }
    }
    if (now == root && chs > 1)
    {
        g.insert(now);
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        to[u].push_back(v), to[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        if (dfn[i] == 0)
        {
            root = i, tarjan(i);
        }
    }
    cout << g.size() << endl;
    for (int x : g)
    {
        cout << x << " ";
    }
    return 0;
}