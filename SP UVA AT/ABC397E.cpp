#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> g[200005];
int n, k, ok, sz[200005];
void dfs(int now, int from)
{
    sz[now] = 1;
    int chs = g[now].size() - (from != 0);
    for (int i = 0; i < (int)g[now].size() && ok; i++)
    {
        int nxt = g[now][i];
        if (nxt == from)
        {
            continue;
        }
        dfs(nxt, now);
        sz[now] += sz[nxt], chs -= (sz[nxt] == 0);
    }
    if (ok)
    {
        if (sz[now] == k)
        {
            chs > 2 ? ok = 0 : sz[now] = 0;
        }
        else if (sz[now] > k || (sz[now] < k && chs >= 2))
        {
            ok = 0;
        }
    }
}
int main()
{
    cin >> n >> k;
    for (int i = 1; i < n * k; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v), g[v].emplace_back(u);
    }
    ok = 1, dfs(1, 0);
    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}