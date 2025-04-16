#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
long long dis[200005], dis2[200005], d1[200005], d2[200005], qz2[200005], len, ans, n1, n2;
vector<int> g[200005];
void dfs(int now, int from, int op)
{
    for (int nxt : g[now])
    {
        if (nxt == from)
        {
            continue;
        }
        op == 1 ? dis[nxt] = dis[now] + 1 : dis2[nxt] = dis2[now] + 1;
        dfs(nxt, now, op);
    }
}
void fc(long long n, int op)
{
    for (int i = 1; i <= n; i++)
    {
        g[i].clear();
    }
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v), g[v].emplace_back(u);
    }
    dis[1] = 0, dfs(1, 0, 1);
    int p1 = max_element(dis + 1, dis + 1 + n) - dis;
    dis[p1] = 0, dfs(p1, 0, 1);
    int p2 = max_element(dis + 1, dis + 1 + n) - dis;
    len = max(len, dis[p2]);
    dis2[p2] = 0, dfs(p2, 0, 2);
    for (int i = 1; i <= n; i++)
    {
        long long d = max(dis[i], dis2[i]);
        op == 1 ? d1[i] = d : d2[i] = d;
    }
}
int main()
{
    cin >> n1;
    fc(n1, 1);
    cin >> n2;
    fc(n2, 2);
    sort(d1 + 1, d1 + n1 + 1), sort(d2 + 1, d2 + n2 + 1); // 断点延申的最长距离
    for (int i = 1; i <= n2; i++)
    {
        qz2[i] = qz2[i - 1] + d2[i];
    }
    for (int i = 1; i <= n1; i++)
    {
        int p = upper_bound(d2 + 1, d2 + 1 + n2, len - (d1[i] + 1)) - d2 - 1; // 找到所有不如之前最大直径的方案
        ans += p * len + (n2 - p) * (d1[i] + 1) + qz2[n2] - qz2[p];
    }
    cout << ans << endl;
    return 0;
}