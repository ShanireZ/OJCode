#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> es[305];
int n, m, pos, h[305], c[305], vis[305];
void dfs(int now)
{
    vis[now] = 1;
    for (int nxt : es[now])
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
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        if (h[u] > h[v])
        {
            es[u].push_back(v), c[v]++;
        }
        else if (h[u] < h[v])
        {
            es[v].push_back(u), c[u]++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (c[i] == 0)
        {
            pos = i, dfs(i);
            break;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            cout << "Non" << endl;
            return 0;
        }
    }
    cout << "Oui, j'ai trouve la solution." << endl;
    cout << pos << endl;
    return 0;
}