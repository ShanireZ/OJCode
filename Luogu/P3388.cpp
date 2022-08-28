#include <iostream>
using namespace std;
int n, m, npos, ans, root;
int pre[200005], to[200005], last[20005], dfn[20005], low[20005], isg[20005];
void addEdge(int u, int v, int id)
{
    pre[id] = last[u], to[id] = v;
    last[u] = id;
}
void tarjan(int now, int from)
{
    dfn[now] = low[now] = ++npos;
    int cnt = 0;
    for (int i = last[now]; i; i = pre[i])
    {
        if ((i ^ from) == 1)
        {
            continue;
        }
        int t = to[i];
        if (dfn[t] == 0)
        {
            tarjan(t, i), cnt++;
            low[now] = min(low[now], low[t]);
            if (now != root && dfn[now] <= low[t])
            {
                isg[now] = 1;
            }
        }
        else
        {
            low[now] = min(low[now], dfn[t]);
        }
    }
    if (now == root && cnt > 1)
    {
        isg[now] = 1;
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        addEdge(a, b, i * 2), addEdge(b, a, i * 2 + 1);
    }
    for (int i = 1; i <= n; i++)
    {
        if (dfn[i] == 0)
        {
            root = i;
            tarjan(root, 0);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        ans += isg[i];
    }
    cout << ans << endl;
    for (int i = 1; i <= n; i++)
    {
        if (isg[i])
        {
            cout << i << " ";
        }
    }
    return 0;
}