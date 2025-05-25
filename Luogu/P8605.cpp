#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> g[10005];
long long dg[10005];
int main()
{
    long long n, m, ans = 0;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v), g[v].push_back(u);
        dg[u]++, dg[v]++;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < (int)g[i].size(); j++)
        {
            int x = g[i][j];
            ans += (dg[x] - 1) * (dg[i] - 1);
        }
    }
    cout << ans << endl;
    return 0;
}