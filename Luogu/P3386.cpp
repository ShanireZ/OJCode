#include <iostream>
#include <vector>
using namespace std;
vector<int> es[505];
int n, m, e, ans, usd[505], a[505], b[505];
bool dfs(int now, int t)
{
    if (usd[now] == t)
    {
        return 0;
    }
    usd[now] = t;
    for (int i = 0; i < es[now].size(); i++)
    {
        int to = es[now][i];
        if (b[to] == 0 || dfs(b[to], t))
        {
            a[now] = to, b[to] = now;
            return 1;
        }
    }
    return 0;
}
int main()
{
    cin >> n >> m >> e;
    for (int i = 1; i <= e; i++)
    {
        int u, v;
        cin >> u >> v;
        es[u].push_back(v);
    }
    for (int i = 1; i <= n; i++)
    {
        ans += dfs(i, i);
    }
    cout << ans << endl;
    return 0;
}