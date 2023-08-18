#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int n, npos, u, v, ans, dfn[200005], low[200005];
vector<int> to[200005];
void tarjan(int now, int from)
{
    dfn[now] = low[now] = ++npos;
    for (int nxt : to[now])
    {
        if (from == nxt)
        {
            continue;
        }
        if (dfn[nxt] == 0)
        {
            tarjan(nxt, now);
            low[now] = min(low[now], low[nxt]);
            if (now != u && low[nxt] >= dfn[now] && dfn[v] >= dfn[nxt])
            {
                ans = min(ans, now);
            }
        }
        else
        {
            low[now] = min(low[now], dfn[nxt]);
        }
    }
}
int main()
{
    cin >> n >> u >> v;
    while (u)
    {
        to[u].push_back(v), to[v].push_back(u);
        cin >> u >> v;
    }
    cin >> u >> v;
    ans = 0x3f3f3f3f, tarjan(u, 0);
    if (ans == 0x3f3f3f3f)
    {
        cout << "No solution" << endl;
    }
    else
    {
        cout << ans << endl;
    }
    return 0;
}
// TAG: 强连通 Tarjan 割点 分类讨论