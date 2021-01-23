#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int vis[10005], times[10005];
vector<int> g[10005];
int dfs(int x)
{
    if (vis[x] == 0)
    {
        vis[x] = 1;
        int maxt = 0;
        for (int i = 0; i < g[x].size(); i++)
        {
            maxt = max(maxt, dfs(g[x][i]));
        }
        times[x] += maxt;
    }
    return times[x];
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int id, len, fa;
        cin >> id >> len >> fa;
        times[id] = len;
        while (fa != 0)
        {
            g[fa].push_back(id);
            cin >> fa;
        }
    }
    cout << dfs(1);
    return 0;
}