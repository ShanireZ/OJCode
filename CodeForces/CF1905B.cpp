#include <algorithm>
#include <iostream>
using namespace std;
#define MX 100005
int to[MX * 2], pre[MX * 2], last[MX], cnt[MX], ans, epos, root;
void addEdge(int u, int v, int id)
{
    to[id] = v, pre[id] = last[u];
    last[u] = id;
}
void dfs(int now, int fa)
{
    if (now != root && cnt[now] == 1) // 叶节点个数
    {
        ans++;
        return;
    }
    for (int i = last[now]; i; i = pre[i])
    {
        if (to[i] != fa)
        {
            dfs(to[i], now);
        }
    }
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        ans = epos = 0, root = 1;
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cnt[i] = last[i] = 0;
        }
        for (int i = 1; i < n; i++)
        {
            int u, v;
            cin >> u >> v;
            addEdge(u, v, ++epos), addEdge(v, u, ++epos);
            cnt[u]++, cnt[v]++;
            root = (cnt[u] > cnt[root] ? u : root);
            root = (cnt[v] > cnt[root] ? v : root);
        }
        dfs(root, 0);
        cout << ans / 2 + ans % 2 << endl;
    }
    return 0;
}