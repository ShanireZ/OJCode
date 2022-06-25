#include <algorithm>
#include <iostream>
using namespace std;
#define MX 8000005
int n, m, k, epos, npos, spos, gpos;
int to[MX], pre[MX], last[MX];
int dfn[MX], low[MX], g[MX], s[MX];
void addEdge(int u, int v)
{
    pre[++epos] = last[u];
    last[u] = epos, to[epos] = v;
}
void tarjan(int now)
{
    dfn[now] = low[now] = ++npos;
    s[++spos] = now;
    for (int i = last[now]; i != 0; i = pre[i])
    {
        int t = to[i];
        if (dfn[t] == 0)
        {
            tarjan(t);
            low[now] = min(low[now], low[t]);
        }
        else if (g[t] == 0)
        {
            low[now] = min(low[now], dfn[t]);
        }
    }
    if (dfn[now] == low[now])
    {
        gpos++;
        while (s[spos] != now)
        {
            g[s[spos--]] = gpos;
        }
        g[s[spos--]] = gpos;
    }
}
int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) // 1~n:是关键点 n+1~2n:不是关键点
    {
        int a, b;
        cin >> a >> b;
        addEdge(a + n, b);
        addEdge(b + n, a);
    }
    for (int i = 1; i <= k; i++) // 2n+1~3n:包含当前数的前缀区间有关键点 3n+1~4n:没有
    {
        int w, a, b;
        cin >> w;
        for (int j = 1; j <= w; j++)
        {
            cin >> a;
            // 满足题意的条件下，每个块内只有1个关键点:
            // a_i是->[包含a_i的前缀区间有] 包含a_i-1的前缀区间没有
            // 包含a_i-1的前缀区间有->a_i不是 包含a_i的前缀区间有
            // 包含a_i的前缀区间没有->[a_i不是] 包含a_i-1的前缀区间没有
            addEdge(a, n * 2 + a);
            addEdge(n * 3 + a, a + n);
            if (j > 1)
            {
                addEdge(a, n * 3 + b);
                addEdge(n * 2 + b, n + a);
                addEdge(n * 2 + b, n * 2 + a);
                addEdge(n * 3 + a, n * 3 + b);
            }
            b = a;
        }
    }
    for (int i = 1; i <= n * 4; i++)
    {
        if (dfn[i] == 0)
        {
            tarjan(i);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (g[i] == g[i + n] || g[i + n * 2] == g[i + n * 3])
        {
            cout << "NIE" << endl;
            return 0;
        }
    }
    cout << "TAK" << endl;
    return 0;
}