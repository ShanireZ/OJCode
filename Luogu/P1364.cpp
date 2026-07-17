#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> to[105];
long long tot[105], sz[105], fa[105], w[105], n, root, sum, ans;
void dfs1(int now, int step)
{
    sz[now] = w[now], tot[root] += step * w[now];
    for (int nxt : to[now])
    {
        dfs1(nxt, step + 1);
        sz[now] += sz[nxt];
    }
}
void dfs2(int now)
{
    if (now != root)
    {
        tot[now] = tot[fa[now]] - sz[now] * 1 + (sum - sz[now]) * 1;
    }
    if (tot[ans] > tot[now] || (tot[ans] == tot[now] && now < ans))
    {
        ans = now;
    }
    for (int nxt : to[now])
    {
        if (nxt != 0)
        {
            dfs2(nxt);
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int u, v;
        cin >> w[i] >> u >> v;
        to[i].push_back(u);
        to[i].push_back(v);
        fa[u] = fa[v] = i, sum += w[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if (fa[i] == 0)
        {
            root = i;
        }
    }
    ans = root;
    dfs1(root, 0);
    dfs2(root);
    cout << tot[ans] << endl;
    return 0;
}