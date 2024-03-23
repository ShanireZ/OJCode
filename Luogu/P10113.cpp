#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> to[100005];
int n, m, q, ans, maxn[100005], dp[100005], anc[100005][20];
void dfs(int now)
{
    maxn[now] = max(now, maxn[anc[now][0]]);
    dp[now] = dp[anc[now][0]] + 1;
    for (int k = 1; k < 17; k++)
    {
        anc[now][k] = anc[anc[now][k - 1]][k - 1];
    }
    for (int nxt : to[now])
    {
        anc[nxt][0] = now;
        dfs(nxt);
    }
}
int lca(int x, int y)
{
    if (dp[x] < dp[y])
    {
        swap(x, y);
    }
    for (int k = 16; k >= 0; k--)
    {
        if (dp[anc[x][k]] >= dp[y])
        {
            x = anc[x][k];
        }
    }
    if (x == y)
    {
        return x;
    }
    for (int k = 16; k >= 0; k--)
    {
        if (anc[x][k] != anc[y][k])
        {
            x = anc[x][k], y = anc[y][k];
        }
    }
    return anc[x][0];
}
int main()
{
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        int f;
        cin >> f;
        to[f + 1].push_back(i);
    }
    dfs(1), maxn[1] = 1;
    cin >> q;
    while (q--)
    {
        cin >> m >> ans;
        ans++;
        for (int i = 1; i < m; i++)
        {
            int id;
            cin >> id;
            ans = lca(ans, id + 1);
        }
        cout << maxn[ans] - 1 << endl;
    }
    return 0;
}