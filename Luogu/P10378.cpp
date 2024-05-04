#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> es[100005];
int ans1, ans2, c1, c2, n, m, vis[100005];
void dfs(int now, int op)
{
    op == 1 ? c1++ : c2++;
    vis[now] = 1;
    for (int nxt : es[now])
    {
        if (vis[nxt] == 0)
        {
            dfs(nxt, !op);
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        es[u].push_back(v), es[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            c1 = 0, c2 = 0;
            dfs(i, 1);
            ans1 += min(c1, c2), ans2 += max(c1, c2);
        }
    }
    cout << ans1 << " " << ans2 << endl;
    return 0;
}