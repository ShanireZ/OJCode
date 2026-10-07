#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> to[100005];
long long ans = 1, n, m, dep[100005];
void dfs(int now, int from)
{
    dep[now] = dep[from] + 1;
    for (int nxt : to[now])
    {
        if (nxt == from || dep[nxt] > dep[now])
        {
            continue;
        }
        if (dep[nxt] && dep[nxt] < dep[now])
        {
            ans = ans * (dep[now] - dep[nxt] + 1) % 998244353;
            continue;
        }
        dfs(nxt, now);
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        to[u].push_back(v);
        to[v].push_back(u);
    }
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}