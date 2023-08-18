#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int n, m, root, w[105], nw[105], v[105], nv[105], fa[105], nfa[105], dp[105][505], ans[505];
int npos, gpos, dfn[105], low[105], g[105];
vector<int> to[105], nto[105];
stack<int> s;
void dfs(int now, int prew)
{
    for (int i = prew + nw[now]; i <= m; i++)
    {
        dp[now][i] = max(dp[now][i], dp[nfa[now]][i - nw[now]] + nv[now]);
    }
    for (int nxt : nto[now])
    {
        dfs(nxt, prew + nw[now]);
        for (int i = prew + nw[now] + nw[nxt]; i <= m; i++)
        {
            dp[now][i] = max(dp[now][i], dp[nxt][i]);
        }
    }
}
void tarjan(int now)
{
    dfn[now] = low[now] = ++npos;
    s.push(now);
    for (int nxt : to[now])
    {
        if (dfn[nxt] == 0)
        {
            tarjan(nxt);
            low[now] = min(low[now], low[nxt]);
        }
        else if (g[nxt] == 0)
        {
            low[now] = min(low[now], dfn[nxt]);
        }
    }
    if (dfn[now] == low[now])
    {
        ++gpos;
        while (s.top() != now)
        {
            g[s.top()] = gpos, nw[gpos] += w[s.top()], nv[gpos] += v[s.top()];
            s.pop();
        }
        g[s.top()] = gpos, nw[gpos] += w[s.top()], nv[gpos] += v[s.top()];
        s.pop();
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> fa[i];
        to[fa[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++)
    {
        if (dfn[i] == 0)
        {
            tarjan(i);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int nxt : to[i])
        {
            if (g[i] == g[nxt])
            {
                continue;
            }
            nto[g[i]].push_back(g[nxt]), nfa[g[nxt]] = g[i];
        }
    }
    for (int i = 1; i <= gpos; i++)
    {
        if (nfa[i] == 0)
        {
            dfs(i, 0);
        }
        for (int j = m; j >= 0; j--)
        {
            for (int k = j; k >= 0; k--)
            {
                ans[j] = max(ans[j], ans[j - k] + dp[i][k]);
            }
        }
    }
    cout << ans[m] << endl;
    return 0;
}
// TAG: Tarjan 缩点 强连通 树上DP 依赖背包