#include <iostream>
#include <vector>
using namespace std;
#define MX 100005
int n, root = 1, fa[MX];
long long dp[MX], sz[MX], ans = 1e15;
vector<int> to[MX], w[MX];
void init(int now, int way)
{
    for (int i = 0; i < to[now].size(); i++)
    {
        int nxt = to[now][i];
        if (nxt == fa[now])
        {
            continue;
        }
        fa[nxt] = now;
        init(nxt, w[now][i]);
        sz[now] += sz[nxt];
    }
    if (now != root)
    {
        dp[root] += sz[now] * way;
    }
}
void dfs(int now, int way)
{
    if (now != root)
    {
        dp[now] = dp[fa[now]] - way * sz[now] + way * (sz[root] - sz[now]);
    }
    for (int i = 0; i < to[now].size(); i++)
    {
        int nxt = to[now][i];
        if (nxt == fa[now])
        {
            continue;
        }
        dfs(nxt, w[now][i]);
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> sz[i];
    }
    for (int i = 1; i < n; i++)
    {
        int a, b, l;
        cin >> a >> b >> l;
        to[a].push_back(b), to[b].push_back(a);
        w[a].push_back(l), w[b].push_back(l);
    }
    init(root, 0);
    dfs(root, 0);
    for (int i = 1; i <= n; i++)
    {
        ans = min(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}