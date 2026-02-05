#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> es[5005], len[5005];
long long n, k, ans, dep[5005];
void dfs(int now, int fa, long long dis)
{
    if (dep[now] == k)
    {
        ans += dis;
        return;
    }
    for (int i = 0; i < es[now].size(); i++)
    {
        int x = es[now][i];
        if (x == fa)
        {
            continue;
        }
        dep[x] = dep[now] + 1;
        dfs(x, now, dis + len[now][i]);
    }
}
int main()
{
    cin >> n >> k;
    for (int i = 1; i < n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        es[u].push_back(v), len[u].push_back(w);
        es[v].push_back(u), len[v].push_back(w);
    }
    for (int i = 1; i <= n; i++)
    {
        fill(dep + 1, dep + 1 + n, 0);
        dfs(i, -1, 0);
    }
    cout << ans << endl;
    return 0;
}