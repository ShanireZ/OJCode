#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> es[100005];
long long n, k, ans, dep[100005], w[100005];
void dfs(int now, int fa)
{
    if (dep[now] <= k + k)
    {
        ans += w[now];
    }
    for (int x : es[now])
    {
        if (x == fa)
        {
            continue;
        }
        dep[x] = dep[now] + 1;
        dfs(x, now);
    }
}
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
    }
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        es[u].push_back(v), es[v].push_back(u);
    }
    dfs(1, -1);
    cout << ans << endl;
    return 0;
}