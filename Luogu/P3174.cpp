#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define MX 300005
vector<int> to[MX];
int n, m, ans, root = 1, mmc[MX], zson[MX], cson[MX]; // mmc[x]:從x開始向下構成的最大毛毛蟲
void dfs(int now, int fa)
{
    int sz = to[now].size();
    mmc[now] = sz - (now != root) + 1; // 如果不是root則sz包含父親 +1表示加的自身
    for (int nxt : to[now])
    {
        if (nxt == fa)
        {
            continue;
        }
        dfs(nxt, now);
        mmc[now] = max(mmc[now], mmc[nxt] + sz - (now != root));
        if (mmc[zson[now]] < mmc[nxt])
        {
            cson[now] = zson[now];
            zson[now] = nxt;
        }
        else if (mmc[cson[now]] < mmc[nxt])
        {
            cson[now] = nxt;
        }
    }
    // 以now作為中轉
    if (zson[now] == 0) // 沒子節點
    {
        ans = max(ans, sz + 1);
    }
    else if (cson[now] == 0) // 只有一個子節點
    {
        ans = max(ans, sz + mmc[zson[now]]);
    }
    else // 至少兩個子節點
    {
        ans = max(ans, sz - 1 + mmc[zson[now]] + mmc[cson[now]]);
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
    dfs(root, 0);
    cout << ans << endl;
    return 0;
}