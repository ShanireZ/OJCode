#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> to[50005];
long long tot[50005], sz[50005], n, ans = 1;
void dfs1(int now, int from, int step)
{
    sz[now] = 1, tot[1] += step;
    for (int nxt : to[now])
    {
        if (nxt == from)
        {
            continue;
        }
        dfs1(nxt, now, step + 1);
        sz[now] += sz[nxt];
    }
}
void dfs2(int now, int from)
{
    if (now != 1)
    {
        tot[now] = tot[from] - sz[now] * 1 + (n - sz[now]) * 1;
    }
    if (tot[ans] > tot[now] || (tot[ans] == tot[now] && now < ans))
    {
        ans = now;
    }
    for (int nxt : to[now])
    {
        if (nxt == from)
        {
            continue;
        }
        dfs2(nxt, now);
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        to[u].push_back(v);
        to[v].push_back(u);
    }
    dfs1(1, 0, 0);
    dfs2(1, 0);
    cout << ans << " " << tot[ans] << endl;
    return 0;
}