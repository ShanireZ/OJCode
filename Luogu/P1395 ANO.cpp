#include <iostream>
#include <vector>
using namespace std;
vector<int> es[50005];
int n, root, tot, sz[50005], zson[50005];
void dfs(int now, int fa)
{
    sz[now] = 1;
    for (int nxt : es[now])
    {
        if (nxt == fa)
        {
            continue;
        }
        dfs(nxt, now), sz[now] += sz[nxt];
        zson[now] = max(zson[now], sz[nxt]);
    }
    zson[now] = max(zson[now], n - sz[now]);
    if (zson[now] < zson[root] || (zson[now] == zson[root] && now < root))
    {
        root = now;
    }
}
void dfs2(int now, int fa, int dp)
{
    tot += dp;
    for (int nxt : es[now])
    {
        if (nxt == fa)
        {
            continue;
        }
        dfs2(nxt, now, dp + 1);
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        es[u].push_back(v), es[v].push_back(u);
    }
    zson[root] = n, dfs(1, 0);
    dfs2(root, 0, 0);
    cout << root << " " << tot << endl;
    return 0;
}