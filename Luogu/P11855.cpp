#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define MX 1000005
int a[MX], p1[MX], p2[MX];
vector<int> to[MX];
void dfs(int now, int fa)
{
    int sum = p2[now];
    p1[now] += p1[fa], sum += p2[fa];
    for (int i = 0; i < (int)to[now].size(); i++)
    {
        int nxt = to[now][i];
        if (nxt == fa)
        {
            continue;
        }
        dfs(nxt, now);
        sum += p2[nxt];
    }
    a[now] += sum + p1[now];
}
int main()
{
    int n, m, q, root = 1;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        to[u].push_back(v), to[v].push_back(u);
    }
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int p, x, y;
        cin >> p >> x >> y;
        (p == 1) ? p1[x] += y : p2[x] += y;
    }
    dfs(root, 0);
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        int x;
        cin >> x;
        cout << a[x] << "\n";
    }
    return 0;
}