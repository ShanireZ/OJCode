#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> to[200005];
long long sz[200005], ans[200005], cost[200005], n, maxa;
void dfs1(int now, int fa)
{
    sz[now] = 1;
    for (int nxt : to[now])
    {
        if (nxt == fa)
        {
            continue;
        }
        dfs1(nxt, now);
        sz[now] += sz[nxt], cost[now] += cost[nxt];
    }
    cost[now] += sz[now];
}
void dfs2(int now, int fa)
{
    if (now != 1)
    {
        ans[now] = ans[fa] + n - 2 * sz[now];
        maxa = max(maxa, ans[now]);
    }
    for (int nxt : to[now])
    {
        if (nxt == fa)
        {
            continue;
        }
        dfs2(nxt, now);
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        to[u].push_back(v), to[v].push_back(u);
    }
    dfs1(1, 0);
    maxa = ans[1] = cost[1];
    dfs2(1, 0);
    cout << maxa << endl;
    return 0;
}
// TAG: 树的重心 树上DP