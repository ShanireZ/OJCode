#include <iostream>
using namespace std;
int usd[105], a[105], b[105], last[105], es[10005][2], pos;
bool dfs(int now, int tag)
{
    if (usd[now] == tag)
    {
        return 0;
    }
    usd[now] = tag;
    for (int i = last[now]; i != 0; i = es[i][1])
    {
        int to = es[i][0];
        if (b[to] == 0 || dfs(b[to], tag))
        {
            b[to] = now, a[now] = to;
            return 1;
        }
    }
    return 0;
}
int main()
{
    int n, m;
    cin >> m >> n;
    int u, v;
    cin >> u >> v;
    while (u != -1)
    {
        es[++pos][0] = v;
        es[pos][1] = last[u];
        last[u] = pos;
        cin >> u >> v;
    }
    int cnt = 0;
    for (int i = 1; i <= m; i++)
    {
        cnt += dfs(i, i);
    }
    cout << cnt << endl;
    for (int i = 1; i <= m; i++)
    {
        if (a[i])
        {
            cout << i << " " << a[i] << endl;
        }
    }
    return 0;
}