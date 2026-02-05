#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> es[100005];
int n, mxdp, dep[100005];
void dfs(int now, int fa)
{
    for (int x : es[now])
    {
        if (x == fa)
        {
            continue;
        }
        dep[x] = dep[now] + 1;
        mxdp = max(mxdp, dep[x]);
        dfs(x, now);
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        es[u].push_back(v), es[v].push_back(u);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++)
    {
        cout << (i - 1) * 2 - min(mxdp, i - 1) << endl;
    }
    return 0;
}