#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> es[100005];
int T, n, k, sz[100005];
void dfs(int now, int from)
{
    sz[now] = 1;
    for (int i = 0; i < es[now].size(); i++)
    {
        if (es[now][i] == from)
        {
            continue;
        }
        dfs(es[now][i], now);
        sz[now] += sz[es[now][i]];
    }
    if (sz[now] == k) // 少了继续向上累计，多了就分不出恰好大小的
    {
        sz[now] = 0;
    }
}
int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
        {
            es[i].clear(), sz[i] = 0;
        }
        for (int i = 1; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            es[a].push_back(b), es[b].push_back(a);
        }
        dfs(1, 0);
        if (sz[1] == 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}