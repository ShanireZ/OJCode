#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
int n, m, vis[600005];
set<int> s[300005];
vector<int> to[600005];
void dfs(int now, int g)
{
    vis[now] = g;
    s[g].insert(now > n ? now - n : now);
    for (int nxt : to[now])
    {
        if (vis[nxt])
        {
            continue;
        }
        dfs(nxt, g);
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        to[u].push_back(v + n);
        to[v + n].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            dfs(i, i);
        }
        cout << n - s[vis[i]].size() << endl;
    }
    return 0;
}