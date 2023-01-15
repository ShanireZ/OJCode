#include <iostream>
#include <set>
using namespace std;
int g[1005][1005];
set<int> s[1005];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u][v] = g[v][u] = 1;
        s[u].insert(v), s[v].insert(u);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << g[i][j] << " ";
        }
        cout << "\n";
    }
    for (int i = 1; i <= n; i++)
    {
        cout << s[i].size() << " ";
        for (auto it = s[i].begin(); it != s[i].end(); it++)
        {
            cout << *it << " ";
        }
        cout << "\n";
    }
    return 0;
}