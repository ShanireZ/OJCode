#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> to[100005];
int n, m, g, vis[100005];
void dfs(int now)
{
    vis[now] = 1;
    for (int nxt : to[now])
    {
        if (vis[nxt] == 0)
        {
            dfs(nxt);
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
        to[u].push_back(v);
        to[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            dfs(i), g++;
        }
    }
    cout << g - 1 << " ";
    cout << (g - 1 + g - 1 + n - 1) / n << endl;
    return 0;
}