#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define MX 20005
vector<int> to[MX];
int n, m, cnt, npos, root, g[MX], dfn[MX], low[MX];
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
            if (low[nxt] >= dfn[now] && now != root)
            {
                g[now] = 1;
            }
        }
        else
        {
            low[now] = min(low[now], dfn[nxt]);
        }
    }
    if (now == root && chs > 1)
    {
        g[now] = 1;
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
    for (int i = 1; i <= n; i++)
    {
        cnt += g[i];
    }
    cout << cnt << endl;
    for (int i = 1; i <= n; i++)
    {
        if (g[i])
        {
            cout << i << " ";
        }
    }
    return 0;
}