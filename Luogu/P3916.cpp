#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//!反向建图 + dfs
//!目的是找到每个点能够到达的编号最大的点
//!反向建图并从大到小遍历每个点
//!点x能从方向图到达的点 这些点也能从正向图到达点x
//!因为从大到小遍历 所以点x就是它们能够到达的编号最大的点
vector<int> g[100005];
int ans[100005];
void dfs(int x, int maxd)
{
    if (ans[x] == 0)
    {
        ans[x] = maxd;
        for (int i = 0; i < g[x].size(); i++)
        {
            int id = g[x][i];
            dfs(id, maxd);
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[v].push_back(u);
    }
    for (int i = n; i >= 1; i--)
    {
        dfs(i, i);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}